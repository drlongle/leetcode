class Iterator
{
private:
    vector<int>::iterator st,ed ;
    int ind ;
public:
    Iterator(vector<int>::iterator st,vector<int>::iterator ed)
    {
        this->st=st ;
        this->ed=ed ;
    }
    int next()
    {
        int ret=*st ;
        st++ ;
        return ret ;
    }
    bool hasNext()
    {
        return !(st==ed) ;
    }
};

class ZigzagIterator {
private:
    list<Iterator*>li ;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if(!v1.empty())
            li.push_back(new Iterator(v1.begin(),v1.end())) ;

        if(!v2.empty())
            li.push_back(new Iterator(v2.begin(),v2.end())) ;
    }

    int next() {
        auto it=li.begin() ;
        int ret=(*it)->next() ;

        if((*it)->hasNext())
        {
            li.push_back(*it) ;
        }
        li.erase(it) ;
        return ret ;
    }

    bool hasNext() {
        return !li.empty() ;
    }
};
