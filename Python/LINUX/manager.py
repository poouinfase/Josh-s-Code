from multiprocessing.managers import BaseManager
from time import sleep
import os


class MyManager(BaseManager):
    pass


def daem(lib):
    sleep(1)
    print(lib)
    quit()


if __name__ == "__main__":
    MyManager.register('list', list)
    mana = MyManager()
    pid = os.fork()
    if pid == 0:
        daem(mana.list())
    mana.list().append(0)
    mana.close()

