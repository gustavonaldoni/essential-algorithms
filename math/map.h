float Map(float, float, float, float, float);

float Map(float n, float start1, float stop1, float start2, float stop2)
{
    if (stop1 == start1)
        return (float) 0;
        
    return start2 + ((n - start1) * (stop2 - start2) / (stop1 - start1));
}