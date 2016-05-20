#make clean
#phpize
#./configure --enable-emeldsp
make 
make test
sudo make install
sudo /etc/init.d/httpd restart
