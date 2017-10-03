import library

engine = library.Engine()

engine.readFile("book.txt", "book")
engine.readFile("film.txt", "film")
engine.readFile("periodical.txt", "periodical")
engine.readFile("video.txt", "video")

print("1) Search by call number.")
print("2) Search by title.")
print("3) Search by subject.")
print("4) Search other.")
option = input("Enter an option: ")
term = input("Enter search term: ")

engine.search(option, term)
engine.displayResults()