import abc

#Classes
class Media:
	def __init__(self):
		return

	def compareCallNum(self, term):
		return term in self.callNum

	def compareTitle(self, term):
		return term in self.title

	def compareSubjects(self, term):
		return term in self.subjects

	@abc.abstractmethod
	def compareOther(self, term):
		pass

	@abc.abstractmethod
	def display(self):
		pass

class Book(Media):
	def __init__(self, data):
		self.callNum = data[0]
		self.title = data[1]
		self.subjects = data[2]
		self.author = data[3]
		self.description = data[4]
		self.publisher = data[5]
		self.city = data[6]
		self.year = data[7]
		self.series = data[8]
		self.notes = data[9]

	def compareOther(self, term):
		return ((term in self.year) or 
				(term in self.notes) or 
				(term in self.description))

	def display(self):
		print("---------------------------")
		print("Call Num: %s" % self.callNum)
		print("Title: %s" % self.title)
		print("Subjects: %s" % self.subjects)
		print("Author: %s" % self.author)
		print("Description: %s" % self.description)
		print("Publisher: %s" % self.publisher)
		print("City: %s" % self.city)
		print("Year: %s" % self.year)
		print("Series: %s" % self.series)
		print("Notes: %s" % self.notes)

class Periodical(Media):
	def __init__(self, data):
		self.callNum = data[0]
		self.title = data[1]
		self.subjects = data[2]
		self.author = data[3]
		self.description = data[4]
		self.publisher = data[5]
		self.publishingHistory = data[6]
		self.series = data[7]
		self.notes = data[8]
		self.related = data[9]
		self.otherTitle = data[10]
		self.docNum = data[11]

	def compareOther(self, term):
		return ((term in self.series) or 
				(term in self.notes) or 
				(term in self.description) or
				(term in self.otherTitle))

	def display(self):
		print("---------------------------")
		print("Call Num: %s" % self.callNum)
		print("Title: %s" % self.title)
		print("Subjects: %s" % self.subjects)
		print("Author: %s" % self.author)
		print("Description: %s" % self.description)
		print("Publisher: %s" % self.publisher)
		print("Publishing History: %s" % self.publishingHistory)
		print("Series: %s" % self.series)
		print("Notes: %s" % self.notes)
		print("Related: %s" % self.related)
		print("Other Title: %s" % self.otherTitle)
		print("Doc Num: %s" % self.docNum)

class Film(Media):
	def __init__(self, data):
		self.callNum = data[0]
		self.title = data[1]
		self.subjects = data[2]
		self.director = data[3]
		self.notes = data[4]
		self.year = data[5]

	def compareOther(self, term):
		return ((term in self.year) or 
				(term in self.notes) or 
				(term in self.director))

	def display(self):
		print("---------------------------")
		print("Call Num: %s" % self.callNum)
		print("Title: %s" % self.title)
		print("Subjects: %s" % self.subjects)
		print("Year: %s" % self.year)
		print("Notes: %s" % self.notes)
		print("Director: %s" % self.director)

class Video(Media):
	def __init__(self, data):
		self.callNum = data[0]
		self.title = data[1]
		self.subjects = data[2]
		self.description = data[3]
		self.distributor = data[4]
		self.notes = data[5]
		self.series = data[6]
		self.label = data[7]

	def compareOther(self, term):
		return ((term in self.distributor) or 
				(term in self.notes) or 
				(term in self.description))

	def display(self):
		print("---------------------------")
		print("Call Num: %s" % self.callNum)
		print("Title: %s" % self.title)
		print("Subjects: %s" % self.subjects)
		print("Description: %s" % self.description)
		print("Distributor: %s" % self.distributor)
		print("Series: %s" % self.series)
		print("Notes: %s" % self.notes)
		print("Label: %s" % self.label)

class Engine:
	def __init__(self):
		self.catalog = []
		self.results = []

	def readFile(self, file, type):
		file = open(file, 'r')

		for line in file:
			data = line.split('|')

			if type == 'book':
				book = Book(data)
				self.catalog.append(book)

			elif type == 'film':
				film = Film(data)
				self.catalog.append(film)

			elif type == 'periodical':
				periodical = Periodical(data)
				self.catalog.append(periodical)

			elif type == 'video':
				video = Video(data)
				self.catalog.append(video)

		file.close()

	def search(self, option, term):
		#callNum
		if option == '1':
			for item in self.catalog:
				if item.compareCallNum(term):
					self.results.append(item)
		
		#title
		elif option == '2':
			for item in self.catalog:
				if item.compareTitle(term):
					self.results.append(item)
		
		#subject
		elif option == '3':
			for item in self.catalog:
				if item.compareSubjects(term):
					self.results.append(item)
		#other
		elif option == '4':
			for item in self.catalog:
				if item.compareOther(term):
					self.results.append(item)

	def displayResults(self):
		for item in self.results:
			item.display()