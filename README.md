majority of the code is in morsecopy.c

Short instructions and description:

Use syntax ./morse [file1] [file2]
	-This copies the characters from file1 to file2 by using signal
	comminucation between processes.
	
	-The copying is limited to characters in the following set:
	abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890
	.,:"(?-/ and a space. All uppercase characters get turned into
	lowercase. If an unknown character is copied, it turns into a _ so
	it can be caught in the destination file
