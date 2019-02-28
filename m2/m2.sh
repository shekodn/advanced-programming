#!/bin/bash

#Changes protagonist
sed -i.bu 's/Buck Mulligan/Sergio Diaz/g' copy_book.txt

#Chanegs antagonist
sed -i.bu 's/Haines/Mr. Bean/g' copy_book.txt

# Changes a place
sed -i.bu 's/Lake/Lake Kamanakaka/g' copy_book.txt

# Changes date and time
sed -i.bu 's/Tuesday/FreakyFriday/g' copy_book.txt
sed -i.bu 's/Fi/F1/g' copy_book.txt
sed -i.bu 's/lee/133/g' copy_book.txt
