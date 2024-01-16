class Video(object):
    def __init__(self, path):
        self.path = path

    def play(self):
        from os import startfile
        startfile(self.path)


class Movie_MP4(Video):
    type = "MP4"


movie = Movie_MP4(r"C:\Users\catte\Downloads\tumblr_qtc37coCiB1yagziq.mp4")
if input("Press enter to play, anything else to exit") == '':
    movie.play()
