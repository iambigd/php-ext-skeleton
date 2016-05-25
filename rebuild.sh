# Clean up the build files
make clean
phpize --clean

# build new files

phpize
./configure --enable-foo
make 
make test
sudo make install

sudo /etc/init.d/httpd restart
