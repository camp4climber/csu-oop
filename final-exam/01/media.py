class Media:

    callNumber = ''
    title = ''
    subject = ''
    notes = ''
    items = []

    def __init__(self, callNumber, title, subject, notes):
        self.items = []

        self.callNumber = callNumber
        self.title = title
        self.subject = subject
        self.notes = notes

        self.items.append('Call Number: ' + callNumber)
        self.items.append('Title: ' + title)
        self.items.append('Subject: ' + subject)
        self.items.append('Notes: ' + notes)

    def titleContains(self, word):
        return self.title.find(word) != -1

    def callNumberContains(self, word):
        return self.callNumber.find(word) != -1

    def subjectContains(self, word):
        return self.subject.find(word) != -1

    def otherContains(self, word):
        pass

    def print(self):
        for item in self.items:
            print(item)


