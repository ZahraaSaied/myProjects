import urllib

def read_text():
	qoutes = open("movie_quotes.txt")
	file_contents = qoutes.read()
	print file_contents
	check_profanity(file_contents)
	qoutes.close()
	
def check_profanity(text_to_check):
	connection = urllib.urlopen("http://www.wdylike.appspot.com/?q=" + text_to_check)
	result = connection.read()
	if result == "true":
		print "Profanity Alert!"
	if result == "false":
		print "No Curse Words Found"
	else:
		print "Can't Scan File" 
	connection.close()

	
read_text()