#!/bin/sh

echo "Allow Nginx Web server to access to /var/www !!!"

chown -R www-data:www-data /var/www/*;

echo "Permission 777 open for /var/www !!!"

chown -R 777 /var/www/*;

echo "Make /run/php directory !!!"

mkdir -p /run/php/;

echo "Make process ID Storage !!!"

touch /run/php/php7.4-fpm.pid;

echo "Download wp-cli !!!"

curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar

echo "Permission 777 open for wp-cli.phar !!!"

chmod 777 wp-cli.phar;

echo "Make wp-cli command to wp !!!"

mv wp-cli.phar /usr/local/bin/wp;

echo "wp-cli Begin !!!"

wp core download --allow-root
wp config create --allow-root --dbname=$DB_NAME --dbuser=$DB_USER --dbpass=$DB_PASS --dbhost=$DB_HOST
wp core install --allow-root --url=$WP_URL --title=$WP_TITLE --admin_user=$WP_ADMIN_NAME --admin_password=$WP_ADMIN_PASS --admin_email=${WP_ADMIN_EMAIL}
wp user create --allow-root $DB_USER $DB_EMAIL --user_pass=$DB_PASS --role=subscriber;
wp theme install --allow-root astra
wp theme update  --allow-root astra
wp theme activate --allow-root astra













