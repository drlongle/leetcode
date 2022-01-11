using coord=pair<int,int>;
class SnakeGame {
private:
    int m,n,foodpos{0};
    vector<vector<int>>food;
    deque<coord>deque;
public:
    SnakeGame(int width, int height, vector<vector<int>>& food):n(width),m(height),food(food)
    {
        deque.push_front({0,0});
    }

    int move(string direction) {
        int i=deque.front().first;
        int j=deque.front().second;
        if(direction=="R")
        {
            j++;
        }
        else if(direction=="D")
        {
            i++;
        }
        else if(direction=="L")
        {
            j--;
        }
        else if(direction=="U")
        {
            i--;
        }

        if(i<0 or i>=m or j<0 or j>=n)//boundaries
        {
            return -1;
        }
        coord temp={i,j};
        if(find(deque.begin(),deque.end(),temp)!=deque.end())//check that the head does not bite the body
        {
            if(temp!=deque.back())//not tail
            {
                return -1;
            }
        }
        if(foodpos<food.size() and temp.first==food[foodpos][0] and temp.second==food[foodpos][1] )
        {
            foodpos++;
        }
        else
        {
            deque.pop_back();
        }
        deque.push_front(temp);//push new head
        return foodpos;
    }
};
