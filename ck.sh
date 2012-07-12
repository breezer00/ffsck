for i in 1 2 3 4 5 6 7 8 9 10
do
mkfs -t ext3 /dev/sda3
mount /dev/sda3 /mnt_ext3
cd /mnt_ext3
mkdir Research
cd /mnt/impressions-v1
./impressions inputfile_16G
dd if=/dev/zero count=$i of=/dev/sda3
cd /
umount /dev/sda3
if [ $i -eq 1 ]
then
fsck.ext3 -a /dev/sda3 > /home/huanchen/Documents/Remzi\ Research/logs/fsck_16G_log 2>&1
else
fsck.ext3 -a /dev/sda3 >> /home/huanchen/Documents/Remzi\ Research/logs/fsck_16G_log 2>&1
fi
done