class Solution 
{
    public:
    bool same_line(vector<double>& x,vector<double>& y,vector<double>& z)
    {
        if(x[0]==y[0]&&y[0]==z[0])
        {
            return true;
        }
        if(x[1]==y[1]&&y[1]==z[1])
        {
            return true;
        }
        if(x[0]==y[0]||y[0]==z[0])
        {
            return false;
        }
        return fabs((y[1]-x[1])/(y[0]-x[0])-(z[1]-x[1])/(z[0]-x[0]))<1e-9;
    }
    vector<double> get_center(vector<double>& x,vector<double>& y,vector<double>& z)
    {
        double p1_x=(x[0]+y[0])/2;
        double p1_y=(x[1]+y[1])/2;
        
        double p2_x=(x[0]+z[0])/2;
        double p2_y=(x[1]+z[1])/2;
        
        double v1_x=y[1]-x[1];
        double v1_y=-(y[0]-x[0]);
        
        double v2_x=z[1]-x[1];
        double v2_y=-(z[0]-x[0]);
        
        double t=(v2_y*p2_x-v2_x*p2_y-v2_y*p1_x+v2_x*p1_y)/(v1_x*v2_y-v1_y*v2_x);
        return {p1_x+v1_x*t,p1_y+v1_y*t};
    }
    bool check_inside(vector<double>& x,vector<double>& y,double radius)
    {
        return pow(x[0]-y[0],2)+pow(x[1]-y[1],2)<=pow(radius,2);
    }
    int numPoints(vector<vector<int>>& p, int radius) 
    {
        int result=1;
        double r=(double)radius;
        vector<vector<double>> points;
        for(int i=0;i<p.size();i++)
        {
            points.push_back({(double)p[i][0],(double)p[i][1]});
        }
        for(int i=0;i+2<points.size();i++)
        {
            for(int j=i+1;j+1<points.size();j++)
            {
                vector<double> center={(points[i][0]+points[j][0])/2,(points[i][1]+points[j][1])/2};
                if(check_inside(center,points[i],r))
                {
                    int c=2;
                    for(int a=0;a<points.size();a++)
                    {
                        if(a!=i&&a!=j)
                        {
                            if(check_inside(points[a],center,r))
                            {
                                c++;
                            }
                        }
                    }
                    result=max(result,c);
                    for(int k=j+1;k<points.size();k++)
                    {
                        if(!same_line(points[i],points[j],points[k]))
                        {
                            int c=3;
                            vector<double> center=get_center(points[i],points[j],points[k]);
                            if(check_inside(points[i],center,r))
                            {
                                for(int a=0;a<points.size();a++)
                                {
                                    if(a!=i&&a!=j&&a!=k)
                                    {
                                        if(check_inside(points[a],center,r))
                                        {
                                            c++;
                                        }
                                    }
                                }
                            }
                            result=max(result,c);
                        }
                    }
                }
            }
        }
        return result;
    }
};
