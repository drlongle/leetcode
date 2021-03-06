bool validMountainArray(int* A, int ASize){
    int ptr;
    // Check to see if too short to be a mountain, or if endpoints are wrong
    if (ASize<3) return false;
    if ((A[0]>=A[1])||(A[ASize-1]>=A[ASize-2])) return false;
    ptr=1;
    
    // Move the pointer along the upward slope
    while ((ptr<ASize-1) && (A[ptr]<A[ptr+1])) ptr++;
    
    // Move the pointer along the downward slope
    while ((ptr<ASize-1) && (A[ptr]>A[ptr+1])) ptr++;
    
    // If we've gotten to end after that, voila!, a mountain
    return (ptr==ASize-1);
}
