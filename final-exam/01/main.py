from book import Book


bookList = []
bookList.append(Book('cn1', 't','s','a','n','d','r','c','s','s'))
bookList.append(Book('cn2', 't','s','a','n','d','r','c','s','s'))
bookList.append(Book('cn3', 't','s','a','n','d','r','c','s','s'))
bookList.append(Book('cn4', 't','s','a','n','d','r','c','s','s'))
bookList.append(Book('cn5', 't','s','a','n','d','r','c','s','s'))
bookList.append(Book('cn6', 't','s','a','n','d','r','c','s','s'))

#should print out 5 items from
for book in bookList:
    book.print()
    print('--------------------------------------------------------------------------------------------------------')
