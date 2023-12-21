for(auto it = cmap.begin();it!=cmap.end();it++)
    {
        if(it->second>maxfreq)
        {
            maxfreq = it->second;
        }
        if(it->second<minfreq)
        {
            minfreq = it->second;
        }
    }