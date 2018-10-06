--------------------------------
addRecord
--------------------------------

Define a pointer to record called temp
Define a pointer to record called current
Define a pointer to record called successor

Allocate a heap space for a record and store its address into temp

copy from uaccountno to accountno in the record whose address is at temp
copy from uname to name in the record whose address is at temp
copy from uaddress to address in the record whose address is at temp

if (start is equal to NULL OR accountno in the record whose address is at start is greater than or equal to uaccountno)
    copy from start to next in the record whose address is at temp
    copy from temp to start

else
    copy from start to current
    copy from next in the record whose address is at current to successor

    while (successor does not equal NULL AND accountno in the record whose address is at successor is less than uaccountno)
        copy from successor to current
        copy from next in record whose address is at successor to successor

    copy from temp to next in record whose address is at current
    copy from successor to next in the record whose address is at temp
