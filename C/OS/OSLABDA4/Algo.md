

FFCS:

STEP 1: Start.
STEP 2: Find the first valid element of the list of requests.
STEP 3: Fulfill request and move read write head to specified location.
STEP 4: Remove element from the list. If list if empty go to step 5 else go to step 2.
STEP 5: Stop.


SSTF:

STEP 1: Start.
STEP 2: Find a valid element of the list of requests that has minimum difference between itself and the current location.
STEP 3: Fulfill request and move read write head to specified location.
STEP 4: Remove element from the list. If list if empty go to step 5 else go to step 2.
STEP 5: Stop.

SCAN:

STEP 1: Start
STEP 2: Start moving read write head from current location to maximum location
STEP 3: Fulfill all requests that occur as head moves.
STEP 4: If maximum location is reached got to location 0 else repeat STEP 3.
STEP 5: Stop

CSCAN:

STEP 1: Start
STEP 2: Set target to maximum address of disk.
STEP 3: Start moving read write head from current location to target location
STEP 4: Fulfill all requests that occur as head moves.
STEP 5: If maximum location is reached got to STEP 6 else repeat STEP 4.
STEP 6: If target is 0 set target to maximum address else set target to 0
STEP 7: If request list is empty go to step 8 else go to step 3
STEP 8: Stop

CLOOK:

STEP 1: Start
STEP 2: Find the maximum request in the request list and set target to that
STEP 3: If target is to the left of current position go to STEP 4 else go to STEP 5.
STEP 4: Find minimum request in the request list and set target to that.
STEP 5: Go to target and fulfill all requests that are reached.
STEP 6: If request list is empty go to STEP 7 else go to STEP 2.
STEP 7: Stop

