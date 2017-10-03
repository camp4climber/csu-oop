from media import Media


class Book(Media):

    description = ''
    year = ''
    author = ''
    publisher = ''
    series = ''
    city = ''

    def __init__(self, callNumber, title, subject, author, notes, description, publisher, city, series, year):
        Media.__init__(self, callNumber, title, subject, notes)
        self.description = description
        self.year = year
        self.author = author
        self.publisher = publisher
        self.series = series
        self.city = city
        self.items.append('Description: ' + description)
        self.items.append('Year: ' + year)
        self.items.append('Author: ' + author)
        self.items.append('Publisher: ' + publisher)
        self.items.append('City: ' + city)
        self.items.append('Series: ' + series)
        self.items.insert(0, 'Book:')

    def otherContains(self, word):
        return self.notes.find(word) != -1 or self.description.find(word) != -1 or self.year.find(word) != -1
