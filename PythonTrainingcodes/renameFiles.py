import os

def rename_files():
	#get files names
	files_list = os.listdir(r"C:\Users\ZahRaa\Downloads\million\prank")
	#print files_list
	path = os.getcwd()
	os.chdir(r"C:\Users\ZahRaa\Downloads\million\prank")
	#rename each file
	for file_name in files_list:
		os.rename(file_name,file_name.translate(None, "0123456789"))

rename_files()
	