#!bin/sh

if [ ! -d "/var/lib/mysql/mysql" ]; then

        chown -R mysql:mysql /var/lib/mysql

        # init database
        mysql_install_db --basedir=/usr --datadir=/var/lib/mysql --user=mysql --rpm

        tfile=`mktemp`
        if [ ! -f "$tfile" ]; then
                return 1
        fi
fi

if [ ! -d "/var/lib/mysql/wordpress" ]; then

# - MySQL 데이터베이스에 연결합니다.

# - 권한을 부여합니다.

# - 익명 사용자 계정을 삭제합니다.

# - "테스트" 데이터베이스가 있는 경우 이 데이터베이스를 삭제합니다.

# - 원격 루트 사용자 계정을 삭제합니다.

# - 로컬 호스트의 루트 사용자 암호를 변경합니다.

# - UTF8 인코딩과 "utf8_General_ci" 모음을 사용하여 "wordpress"라는 새 데이터베이스를 만듭니다.

# - 지정한 사용자 이름과 암호로 새 사용자를 만듭니다
# "워드 프레스" 데이터베이스에 대한 모든 권한을 부여합니다.

# - 권한을 다시 부여합니다.
        cat << EOF > /tmp/create_db.sql
USE mysql;
FLUSH PRIVILEGES;
DELETE FROM     mysql.user WHERE User='';
DROP DATABASE test;
DELETE FROM mysql.db WHERE Db='test';
DELETE FROM mysql.user WHERE User='root' AND Host NOT IN ('localhost', '127.0.0.1', '::1');
ALTER USER 'root'@'localhost' IDENTIFIED BY '${DB_ROOT}';
CREATE DATABASE ${DB_NAME} CHARACTER SET utf8 COLLATE utf8_general_ci;
CREATE USER '${DB_USER}'@'%' IDENTIFIED by '${DB_PASS}';
GRANT ALL PRIVILEGES ON wordpress.* TO '${DB_USER}'@'%';
FLUSH PRIVILEGES;
EOF
        # run init.sql
        /usr/bin/mysqld --user=mysql --bootstrap < /tmp/create_db.sql
        rm -f /tmp/create_db.sql
fi
