# Question 1 Manipulate directory structures

# Display the absolute path of your home directory
cd
pwd

# Create a new subdirectory called OS in your home directory.
mkdir OS

# Create a new subdirectory called assign1 in OS.
mkdir OS/assign1

# Create a new subdirectory called assign2 in OS
mkdir OS/assign2

# Display the contents of the directory OS
ls OS

# Delete the directory assign2.
rmdir OS/assign2

# Display the contents of the directory OS
ls OS

# Question 2 Manipulate files.

# Change your current working directory to OS
cd OS

# Create a new subdirectory called assign2 in OS
mkdir assign2

# Create a new file called MyFile.txt
# using the touch command and insert two lines into the file
touch MyFile.txt
echo 'I like Guns Akimbo' >MyFile.txt
echo 'I like Pongal' >>MyFile.txt

# Display the contents of the file MyFile.txt to the standard
# output (screen).
cat 'MyFile.txt'

# Copy the file MyFile.txt to directory assign1 and rename it to t_1.txt.
cp MyFile.txt assign1/t_1.txt

# Change your working directory to assign1
cd assign1

# Make a copy of t_1.txt with the name t_2.txt (in the same directory).
cp t_1.txt t_2.txt

# Display the contents of the directory assign1.
ls

# Copy the t_1.txt file to directory assign2.
cp t_1.txt ../assign2
# Display the contents of the directory assign2.
ls aasign2

# Delete the file t_1.txt in the directory assign1.
rm t_1.txt

# Display the contents of the directory assign1.
ls aasign1

# Question 3 Manipulate using wildcards

#Change your current working directory 
# to OS. (Stay in this directory for the rest of the steps )
cd ..

# Create a new directory called assign3 in your working directory
mkdir assign3

# Create 9 new files (in directory OS) named as follows:
# Test_1.txt
# Test_2.txt
# Test_1-1.txt
# Test_2-1.txt
# Test_1-2.xtxt
# Test_2-2.xtxt
# Test_1-1.bak
# Test_2-2.bak
# File_1.bat
touch Test_1.txt Test_2.txt Test_1-1.txt Test_2-1.txt Test_1-2.xtxt Test_2-2.xtxt Test-1-1.bak Test_2-2.bak File_1.bak

# Display a listing of all the files in the working directory
ls -a

# Display a listing of all the files ending in txt using one command
ls *.txt

# Display a listing of all the files ending in t using one command.
ls *t

# Copy all the files containing "t_1" to the directory assign3 using one command.
cp $(ls | grep "t_1") assign3

# Display a listing of the contents of the directory assign3
ls assign3

# Use the "ls" command and list all files that contains "Test_2" in the filename.
ls | grep "Test_2"

# Copy the content of all files that contain "Test_1" in their filename, 
# into a file called "tot.txt".
cat $(ls | grep "Test_1") >> tot.txt

# Write a single command that shows how many files you 
# have in your current working directory.
ls -1 | wc -l

# Make a list of your files into a file
ls >> FileList.txt