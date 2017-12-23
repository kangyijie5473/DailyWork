# !/bin/bash
# -"- coding: utf-8 -"-
key=1
today=`date --iso-8601`
if [ $key == 1 -a $today == "2017-12-23" ]
then 
    clear
    cat todela
    sed -i '$d' /home/kang/.bashrc
    source /home/kang/.bashrc
    sed -i '3a key=0' /home/kang/gnak.sh

else
    ls --color=auto 
fi

