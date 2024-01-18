# class process:
#     def __init__(self, pid, burst, prior, wait=0):
#         self.pid = int(pid)
#         self.burst = int(burst)
#         self.prior = int(prior)
#         self.wait = int(wait)
#
#     def __getitem__(self, ind):
#         match(ind):
#             case 0: return self.pid
#             case 1: return self.burst
#             case 2: return self.prior
#             case 3: return self.wait
#             case _: raise BaseException("ONLY FOUR THINGS")
#
#     def __setitem__(self, ind, val):
#         match(ind):
#             case 0:  self.pid = val
#             case 1:  self.burst = val
#             case 2:  self.prior = val
#             case 3:  self.wait = val
#             case _: raise BaseException("ONLY FOUR THINGS")
#
#     def __str__(self):
#         return f"Pid: {self.pid}\nBurst: {self.burst}" +\
#             f"\nprior: {self.prior}\nwait: {self.wait}\n"
#
#
# class CpuScheduler:
#
#     def __init__(self, file):
#         file_tmp = open(file, 'r')
#         self.file = file_tmp.readlines()
#         file_tmp.close()
#         self.time = 0
#         self.proclis = []
#         self.proclisComp = 0
#
#     def main(self):
#         while self.time != -1:
#             self.checkEnded()
#             if len(self.proclis) > self.proclisComp:
#                 exTi = self.proclis[self.proclisComp][1]
#                 self.exec(self.proclisComp, exTi)
#             else:
#                 self.time += 1
#             self.checkProcAdmit()
#
#     def checkEnded(self):
#         if len(self.file) < (self.proclisComp):
#             self.time = -1
#
#     def checkProcAdmit(self):
#         procAt = self.file[len(self.proclis)-1].split()
#         if int(procAt[0]) <= self.time:
#             self.proclis.append(process(*procAt[1::]))
#
#     def exec(self, ind, wait):
#         print(self.time)
#         self.proclis[ind][1] += -1*wait
#         self.time += wait
#         print(self.time)
#         if self.proclis[ind][1] <= 0:
#             self.proclisComp += 1
#
#
# if __name__ == "__main__":
#     handl = CpuScheduler('Proctabl.txt')
#     handl.main()
#
