#!bin/sh
if [ -f "./${USER}.42.fr.crt" ] || [ -f "./${USER}.42.fr.key" ]; then
    rm ${USER}.42.fr.crt ${USER}.42.fr.key ../nginx/tools/*
fi
mkcert ${USER}.42.fr
mv ${USER}.42.fr-key.pem ${USER}.42.fr.key
mv ${USER}.42.fr.pem ${USER}.42.fr.crt
cp ${USER}.42.fr.crt ../nginx/tools/.
cp ${USER}.42.fr.key ../nginx/tools/.
