# Kindle-notes-to-Roam
Format your Kindle Clippings.txt for Roam Research using C++.

This is a personal project that is not affilated with Amazon or Roam.

This is a personal attempt to import non-Amazon kindle highlights from documents.

## Features
- Indentifies individual books (Allow you to choose book to import from)
- Indentify Notes from highlights and make then child elements in italics
- Allow you to add tags to the end of the highlights
- Automatically skips over duplicate hightlights
- Writes your notes markdown into an external file "out.txt"

** NOTE: The file "MyClippings.txt" must be copied into the same directory from Kindle
The 'My Clippings.txt' file is located in the 'Documents' folder. You will need to connect your Kindle to your computer via the USB port and browse to the 'Documents' folder in your file browser.

### To run the program, either compile it in C++ in your local machine or run the .exe file.

## Raw Text
```txt
Shoe Dog: A Memoir by the Creator of Nike \( PDFDrive.com \).mobi (Phil Knight)
- Your Highlight at location 4784-4784 | Added on Thursday, 6 August 2020 14:50:31

Maybe the cure for any burnout, I thought, is to just work harder.
==========
Shoe Dog: A Memoir by the Creator of Nike \( PDFDrive.com \).mobi (Phil Knight)
- Your Note at location 4784 | Added on Thursday, 6 August 2020 14:50:49

Is it though?
==========
Autobiography of Benjamin Franklin (Benjamin Franklin)
- Your Bookmark at location 491 | Added on Wednesday, 18 December 2019 20:33:51


==========
Essentialism: The Disciplined Pursuit of Less \( PDFDrive.com \).mobi (Mckeown, Greg)
- Your Highlight at location 1259-1260 | Added on Monday, 17 August 2020 08:33:36

“What am I deeply passionate about?” and “What taps my talent?” and “What meets a significant need in the world?”
==========
Essentialism: The Disciplined Pursuit of Less \( PDFDrive.com \).mobi (Mckeown, Greg)
- Your Note at location 1260 | Added on Monday, 17 August 2020 08:33:45

Experiment
==========
```
## Terminal Prompt
```txt
What is your source tag?
essentialism [USER INPUT]
The tag for highlights will be #[[essentialism]]
Are you sure? [y]
y [USER INPUT]

Books found include:
0 - Autobiography of Benjamin Franklin (Benjamin Franklin)
1 - Essentialism: The Disciplined Pursuit of Less \( PDFDrive.com \).mobi (Mckeown, Greg)
2 - Shoe Dog: A Memoir by the Creator of Nike \( PDFDrive.com \).mobi (Phil Knight)
Which book's notes do you want to extract?
1 [USER INPUT]
You picked Essentialism: The Disciplined Pursuit of Less \( PDFDrive.com \).mobi (Mckeown, Greg)
Are you sure? [y]
y [USER INPUT]
```

## Exported Text
```txt
- “What am I deeply passionate about?” and “What taps my talent?” and “What meets a significant need in the world?” #[[essentialism]]
	- __Experiment__
```
