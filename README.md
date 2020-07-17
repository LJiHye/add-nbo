# add-nbo
syntax : add-nbo <file1> <file2>  
sample : add-nbo a.bin c.bin

## example
$ echo -n -e \\x00\\x00\\x03\\xe8 > thousand.bin  
$ echo -n -e \\x00\\x00\\x01\\xf4 > five-hundreda.bin  
$ ./add-nbo thousand.bin five-hundred.bin  
1000(0x3e8) + 500(0x1f4) = 1500(0x5dc)

## screenshot
![Screenshot_2020-07-17_13-52-08](https://user-images.githubusercontent.com/45416961/87816092-bf350900-c834-11ea-8f93-e146aa62e3b6.png)
