# MemoryManipulation

In realtime when we try to copy a particular data from source to destination by using memcpy | memmove functions the number bytes copy from source to destination will always be size of the destination, Instead if we use size as sizeof source, it will cause to memory leak. So that by using this template functions, If size of the destination is less than sizeof source than it will produce error at compile time.So we can reduce the risk factor from memory leak or unpredictable behavior.   
