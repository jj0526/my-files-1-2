from tkinter import *

window = Tk()
window.geometry('300x300')
window.title('연습')

b1 = Button(window, text='버튼1')
b1.pace()
b2 = Button(window, text='버튼2')
b2.pack()

window.mainloop()