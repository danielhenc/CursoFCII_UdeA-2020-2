namespace my_namespace
{
    
    int parte_entera(float x)
    {
        int n = x;
        return n;
    }

    float parte_fraccionaria(float x)
    {
        float r = x - parte_entera(x);
        return r;
    }
}

