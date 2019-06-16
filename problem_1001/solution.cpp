/*
1001. Grid Illumination
Difficulty: Hard

On a N x N grid of cells, each cell (x, y) with 0 <= x < N and 0 <= y < N has a lamp.

Initially, some number of lamps are on.  lamps[i] tells us the location of the i-th lamp that is on.  Each lamp that is on illuminates every square on its x-axis, y-axis, and both diagonals (similar to a Queen in chess).

For the i-th query queries[i] = (x, y), the answer to the query is 1 if the cell (x, y) is illuminated, else 0.

After each query (x, y) [in the order given by queries], we turn off any lamps that are at cell (x, y) or are adjacent 8-directionally (ie., share a corner or edge with cell (x, y).)

Return an array of answers.  Each value answer[i] should be equal to the answer of the i-th query queries[i]

Example 1:

Input: N = 5, lamps = [[0,0],[4,4]], queries = [[1,1],[1,0]]
Output: [1,0]
Explanation: 
Before performing the first query we have both lamps [0,0] and [4,4] on.
The grid representing which cells are lit looks like this, where [0,0] is the top left corner, and [4,4] is the bottom right corner:
1 1 1 1 1
1 1 0 0 1
1 0 1 0 1
1 0 0 1 1
1 1 1 1 1
Then the query at [1, 1] returns 1 because the cell is lit.  After this query, the lamp at [0, 0] turns off, and the grid now looks like this:
1 0 0 0 1
0 1 0 0 1
0 0 1 0 1
0 0 0 1 1
1 1 1 1 1
Before performing the second query we have only the lamp [4,4] on.  Now the query at [1,0] returns 0, because the cell is no longer lit.
 */

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstring>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

struct Query {
    Query() { cerr << "This should not be called!" << endl;}
    Query(int c): count(c), light(0) { }
    int count;
    int light;
};

class Solution {
public:

    bool update_row(int row, int delta) {
        bool intersect = false;
        for (auto& cell : cells) {
            if (cell.first.first == row) {
                cell.second.light += delta;
                intersect = true;
            }
        }
        return intersect;
    }

    bool update_column(int column, int delta) {
        bool intersect = false;
        for (auto& cell : cells) {
            if (cell.first.second == column) {
                cell.second.light += delta;
                intersect = true;
            }
        }
        return intersect;
    }

    // the point that line y = y0 + (x-x0) intersects with the y-axis
    bool update_forward(int row, int delta) {
        bool intersect = false;
        for (auto& cell : cells) {
            if (cell.first.second - cell.first.first == row) {
                cell.second.light += delta;
                intersect = true;
            }
        }
        return intersect;
    }

    // the point that line y = y0 - (x-x0) intersects with the y-axis
    bool update_backward(int row, int delta) {
        bool intersect = false;
        for (auto& cell : cells) {
            if (cell.first.second + cell.first.first == row) {
                cell.second.light += delta;
                intersect = true;
            }
        }
        return intersect;
    }

    void print() {
        for (auto& cell: cells) {
            cout << "[" << cell.first.first << "," << cell.first.second << "] -> " << cell.second.light << endl;
        }
    }

    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries)
    {
        vector<int> res;

        for (auto& q : queries) {
            pair<int, int> key{q[0], q[1]};
            auto it = cells.find(key);
            if (it != cells.end())
                ++(it->second.count);
            else
                cells.emplace(make_pair(key, Query(1)));
        }

        for (auto& lamp: lamps) {
            int x = lamp[0], y = lamp[1];
            auto key = make_pair(x, y);
            auto it = cells.find(key);
            if (it != cells.end())
                it->second.light -= 3;
            auto res = lamp_cells.insert(key);
            bool intersect = false;
            intersect |= update_row(x, 1);
            intersect |= update_column(y, 1);
            intersect |= update_forward(y-x, 1);
            intersect |= update_backward(x+y, 1);
            if (!intersect)
                lamp_cells.erase(res.first);
        }


        //print();
        //cout << "---------------" << endl;

        for (auto& q : queries) {
            int x = q[0], y = q[1];
            auto it = cells.find(make_pair(x, y));
            res.push_back(it->second.light > 0);
            if (--(it->second.count) == 0)
                cells.erase(it);
            for (auto& off: offsets) {
                int n_x = x + off[0];
                int n_y = y + off[1];
                pair<int, int> nxy{n_x, n_y};
                auto nit = lamp_cells.find(nxy);
                if (n_x >= 0 && n_x < N && n_y >= 0 && n_y < N && nit != lamp_cells.end()) {

                    update_row(n_x, -1);
                    update_column(n_y, -1);
                    update_forward(n_y-n_x, -1);
                    update_backward(n_x+n_y, -1);
                    
                    auto it = cells.find(nxy);
                    if (it != cells.end())
                        it->second.light += 3;
                    lamp_cells.erase(nit);
                }
            }

            //print();
            //cout << "---------------" << endl;
        }

        return res;
    }

    map<pair<int,int>, Query> cells;
    set<pair<int, int>> lamp_cells;
    vector<vector<int>> offsets{{0,0},{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
};

int main() {
    Solution sol;
    int N;
    vector<vector<int>> lamps, queries;

    N = 5, lamps = {{0,0},{4,4}}, queries = {{1,1},{1,0}};

    // 8 / 38 test cases passed
    // Expected: [1,1]
    N = 5, lamps = {{0,0},{4,4}}, queries = {{1,1},{1,1}};

    // 11 / 38 test cases passed
    // Expected: [1,0]
    N = 5, lamps = {{0,0},{1,0}}, queries = {{1,1},{1,1}};

    // 18 / 38 test cases passed.
    //N = 5, lamps = {{0,0},{0,1},{0,4}}, queries = {{0,0},{0,1},{0,2}};

    // 33 / 38 test cases passed.
    // Expected: [1,0]
    N = 5, lamps = {{0,0},{4,4}}, queries = {{1,1},{1,0}};

    // 34 / 38 test cases passed.
    // Expected: [1,1]
    N = 5, lamps = {{0,0},{4,4}}, queries = {{1,1},{1,1}};
    
    //N = 10000, lamps = {{6873,220},{783,8721},{2148,7662},{6130,155},{8318,2609},{7065,6053},{5224,2756},{5879,8848},{154,4795},{6533,9521},{9485,3659},{1294,5314},{3215,7570},{868,4255},{5763,1037},{8793,9227},{4574,2815},{6519,7784},{9371,2289},{9785,5154},{8504,1676},{1903,245},{7671,4033},{6158,6002},{6718,8258},{5022,2671},{359,7494},{2170,3860},{673,8377},{3555,6158},{4973,2313},{9454,4063},{2385,6794},{2801,3900},{8345,6979},{970,238},{1057,1183},{9432,802},{6460,4733},{1664,1097},{5264,7361},{9049,6568},{4280,8480},{5696,1625},{8065,5544},{2309,6825},{5389,2150},{8556,1848},{6467,7965},{8526,2028},{5788,2326},{1253,6558},{840,6458},{6691,1131},{8663,6906},{1068,1636},{7729,7768},{8039,4958},{31,1691},{4481,9139},{1759,895},{5833,8816},{4867,3314},{7349,7205},{9507,1481},{6300,5144},{4406,9001},{3243,3650},{2797,2990},{2800,7104},{7881,759},{642,83},{9008,1271},{2375,8513},{140,9078},{8811,833},{9515,7055},{3568,3635},{5952,528},{7065,646},{8192,7212},{8413,6032},{3815,876},{9818,6058},{6337,9274},{8448,6465},{4609,932},{3058,6998},{3501,3727},{1257,1983},{8559,2578},{880,4580},{3910,599},{3289,6818},{3939,2253},{1078,6700},{2301,9992},{497,4277},{3725,4735},{6836,1495},{9794,6846},{1154,8175},{6191,6690},{8605,1310},{2408,3103},{7149,7274},{7065,5837},{7999,9739},{6367,3111},{2419,6718},{4780,1147},{558,7270},{5095,9244},{278,6758},{7530,1443},{9161,7656},{2578,8890},{8470,2713},{6723,9344},{4593,2586},{5602,5720},{2212,7297},{7081,2649},{9977,7446},{8214,9263},{6097,3286},{6732,8089},{7520,4708},{6640,2105},{7374,1075},{4605,6375},{1287,205},{5793,1806},{7516,5951},{4222,9662},{6096,4346},{5322,1800},{524,4516},{9647,9957},{4172,8997},{6427,9024},{2880,731},{1553,2535},{4732,5094},{1175,2878},{2664,5292},{694,1211},{3312,982},{1741,6075},{4453,8689},{4926,4828},{6378,7743},{976,5153},{1080,931},{9595,5682},{8218,120},{5807,3913},{6530,7707},{5965,8261},{5714,2316},{8604,4875},{8548,3730},{3142,9440},{931,2292},{24,2592},{4207,8192},{7301,7402},{8365,8855},{3044,8658},{4245,1311},{1966,6670},{6338,4416},{9121,9818},{7462,2216},{3727,8772},{1475,9143},{8559,5312},{2306,19},{395,7796},{1760,3270},{6977,365},{8284,1019},{3555,1273},{7723,5028},{2919,4699},{4292,9991},{8519,6043},{3509,5020},{9505,8851},{8380,6433},{8104,1907},{1534,7974},{5873,1837},{4275,1473},{1223,4409},{5672,7756},{2104,6995},{1164,9218},{6950,6888},{9523,9781},{5687,7197},{262,8891},{7206,4712},{2241,524},{4431,2645},{8628,4262},{5494,3554},{8819,7385},{6737,6019},{3686,7084},{3866,6527},{1849,1558},{8526,6945},{5341,3653},{5840,2551},{7733,2731},{8134,3319},{7066,2236},{3755,9093},{584,9137},{3452,638},{6383,2312},{8379,689},{1714,3905},{5727,3281},{2875,5058},{6418,4132},{5813,4421},{3682,2647},{6321,7813},{7520,4599},{610,4036},{6996,8825},{9649,2200},{9447,6451},{1833,4681},{4007,8689},{1724,2101},{7399,1265},{5100,3213},{6764,4599},{5747,9253},{2673,9098},{8588,4807},{3476,3925},{263,657},{6918,1575},{121,9650},{1087,6355},{9577,5329},{1272,385},{4213,7318},{432,539},{3611,3007},{5160,2705},{4624,637},{3446,5413},{5564,6132},{5798,8848},{396,3135},{8740,4571},{2319,6873},{9731,711},{7802,7460},{8009,5814},{4548,5526},{7617,5311},{362,1752},{2823,8542},{8172,5878},{5424,7121},{1070,7681},{1023,6172},{5912,2320},{7633,2486},{983,7722},{6194,7098},{4874,2877},{3318,8791},{8037,3275},{3089,8000},{7601,9608},{2559,5373},{5498,4653},{8797,7208},{5616,6328},{2254,9761},{4279,9898},{5591,8747},{7623,6231},{2306,5484},{1756,121},{3759,7489},{9719,110},{4911,4360},{8859,4070},{8728,9668},{609,6726},{4164,9820},{1284,2807},{1089,8044},{6134,6791},{6018,3490},{2713,1590},{28,4210},{6135,27},{5866,4355},{6043,8269},{5114,7744},{582,3819},{558,3944},{3371,5380},{8540,5183},{1938,5311},{350,6843},{377,3013},{9923,8039},{6622,6242},{1932,5779},{9894,3064},{1520,7554},{2554,7787},{1160,1850},{485,9077},{4643,3240},{3447,7364},{9876,4313},{6325,9496},{2319,1522},{2454,8390},{8192,6586},{9879,7079},{5379,8107},{8824,3785},{3565,6532},{6190,7709},{1346,2969},{2847,8199},{5948,5601},{8472,3938},{5739,9943},{1866,793},{1551,6747},{6553,7231},{8208,814},{1884,3848},{5671,4377},{2400,158},{4322,2278},{4341,8605},{3876,9061},{9775,4182},{5170,9721},{3670,9584},{263,1769},{6342,4082},{5393,2527},{6944,1163},{738,7340},{6696,651},{6783,6066},{5829,1959},{501,2857},{5795,408},{1071,9339},{164,4956},{4865,8087},{4299,7876},{6672,7617},{7200,9253},{1336,1857},{4831,199},{1621,1504},{5144,6057},{3802,9038},{6672,2619},{5197,2975},{591,3282},{4632,8664},{1345,5767},{330,1143},{1973,2456},{6132,7705},{3297,8566},{6573,4994},{123,6166},{6591,5480},{6449,2880},{2455,6008},{7939,7603},{8488,8080},{4547,8223},{2537,8963},{2140,873},{2242,9625},{7320,171},{8611,6748},{553,5057},{7278,2411},{9809,1292},{5640,1802},{8409,3619},{6188,7121},{5102,9470},{3976,2617},{5631,7289},{1997,5986},{753,1703},{8771,864},{6267,6620},{1299,7449},{4538,3778},{747,9848},{5582,1685},{8958,8382},{6411,6359},{945,5243},{7561,4237},{3391,1385},{677,6031},{38,2930},{3550,2076},{7400,8629},{9816,3348},{6779,7669},{460,1884},{9449,3241},{4182,606},{5425,6366},{8310,8118},{1988,9024},{9216,5814},{2601,6565},{1132,7091},{281,3490},{9830,9029},{3347,3411},{1087,7243},{4794,24},{6554,1621},{6258,6130},{8464,4728},{4598,3498},{1677,6254},{4757,2747},{9616,5923},{3056,5923},{6751,4217},{334,134},{2801,3813},{9673,3755},{6450,3567},{9855,861},{4162,4742},{5329,6907},{9094,4042},{3911,8168},{1670,9280},{313,955},{6445,594},{5816,2000},{2749,3196},{8499,8374},{3096,4224},{2738,5056},{5864,4291},{8207,6148},{6023,2830},{7464,3550},{9336,6781},{8239,6766},{3756,3171},{4042,3286},{3598,3285},{6739,6077},{600,6394},{9592,8302},{3483,1266},{5052,4266},{9115,4444},{133,1042},{6097,845},{5900,958},{3047,2224},{3056,680},{5679,465},{3603,8017},{6141,929},{4363,1196},{3816,373},{8498,238},{4717,3159},{6263,5236},{2252,7267},{9259,221},{5129,1051},{5349,1868},{4540,9652},{8479,135},{8594,5623},{2486,9387},{8250,9137},{2941,5829},{9992,8307},{1915,2266},{1525,9858},{5000,3248},{4957,2552},{2308,467},{7871,2513},{4785,7665},{8961,1520},{1140,5230},{5290,2423},{3224,7361},{3590,4034},{4842,5765},{6934,3725},{1518,2617},{5229,5961},{8808,4129},{2100,1899},{8820,386},{8646,5693},{2208,6633},{3141,3676},{908,9829},{979,9128},{6161,1945},{7418,4391},{295,2219},{9397,1794},{3309,4232},{9060,7125},{2901,2045},{5004,884},{7957,8687},{773,5073},{2695,9301},{8490,2855},{8057,8248},{4700,658},{9134,6634},{4112,7716},{7564,6540},{6860,2386},{3228,5606},{5262,2181},{1533,9427},{2885,7354},{4466,5010},{7446,2338},{8463,3670},{3816,6451},{7967,6455},{9304,6757},{2273,9391},{4374,9621},{9030,9470},{694,8293},{9109,7607},{7889,8586},{2904,1969},{4065,7869},{2380,7942},{9048,9979},{7557,5719},{8858,8053},{1959,9814},{6350,2513},{5294,7722},{2161,839},{1335,7199},{1410,8756},{9765,4419},{9863,3434},{2045,362},{6951,286},{5674,956},{2671,7289},{1130,6914},{1325,2840},{62,8428},{6072,6732},{1598,1677},{4406,8059},{6547,9373},{3075,2365},{8428,8246},{625,4207},{3322,6792},{6899,7891},{5043,8406},{3392,3422},{6994,8119},{3318,8521},{9173,6501},{6229,9617},{1950,5473},{1344,2520},{5859,2621},{1584,8129},{9231,3744},{5328,9543},{3726,3062},{5122,6999},{292,5390},{7448,5089},{4615,682},{4860,5259},{7041,4898},{4952,5054},{7807,8945},{2335,2583},{7620,1239},{3155,7607},{8983,6485},{8492,5380},{1552,276},{9719,8214},{8591,8798},{8436,4571},{5190,6291},{4632,7923},{4026,1670},{9161,7988},{6725,8958},{4293,551},{8615,9750},{3083,8281},{2849,6476},{3583,4603},{9432,5589},{667,8675},{6792,1800},{7337,4297},{8638,9471},{6778,475},{8637,2585},{2386,3977},{5546,8571},{4617,7417},{8384,5866},{4395,8596},{45,3042},{4953,1959},{3315,7474},{7174,6755},{3368,6158},{5931,9054},{5718,1308},{8548,416},{1372,4935},{6625,4071},{7643,6480},{7654,4371},{1321,599},{4267,9754},{1282,982},{5228,1733},{6642,391},{8698,7506},{4300,4361},{6888,2448},{3174,431},{3471,2038},{4811,4000},{6650,732},{8375,7672},{5435,3151},{4191,5702},{8500,8354},{2167,572},{9407,8872},{7401,7299},{1927,2731},{7973,3252},{5292,8312},{6443,8319},{1667,1265},{6274,4440},{964,7305},{5109,7093},{2858,9899},{2609,1953},{391,1524},{1001,557},{7469,9396},{4994,8457},{8597,6402},{6615,7663},{284,7093},{7126,9561},{1025,5371},{5104,630},{9497,9653},{7917,8041},{4971,8649},{630,1642},{8005,6223},{8633,979},{7813,6853},{4089,6067},{3408,6603},{9260,4639},{5854,3256},{8731,2396},{5884,4947},{533,2727},{1209,5498},{5788,3325},{5577,1535},{2614,8163},{549,1141},{6733,1775},{697,424},{4304,1388},{6309,466},{3600,5995},{1789,9383},{9716,4909},{1753,5466},{101,7961},{7493,1013},{3666,4380},{9938,4646},{1406,6020},{9635,2780},{6205,9573},{1297,7102},{779,196},{4232,1012},{532,5854},{5160,2012},{2669,8818},{7140,9206},{3050,2835},{2230,4969},{8438,1799},{6137,9964},{1214,3706},{7934,6605},{8982,5404},{2008,2718},{8562,495},{3248,8610},{6654,2922},{2385,1365},{6279,2392},{3501,5298},{1952,6698},{3430,138},{8958,8193},{6646,2115},{156,2549},{4920,9031},{2984,2545},{1132,161},{5508,1460},{8183,4772},{1126,4401},{2256,5283},{1288,3488},{8949,8010},{4456,8251},{1588,7860},{6937,2338},{6978,8114},{113,7399},{9224,3163},{937,899},{1376,7206},{9680,8591},{6028,5953},{1593,8524},{7648,9358},{7256,6619},{5811,3233},{4648,6390},{9410,6147},{7144,9141},{8989,1074},{5785,570},{4456,46},{8274,6726},{6091,1230},{1933,3793},{499,9001},{4423,1910},{6063,1166},{6851,6564},{4451,6108},{4968,1614},{1832,986},{9454,5852},{4746,2048},{6822,6040},{8217,5596},{223,162},{2249,7631},{5281,5901},{578,2893},{1862,7919},{4720,8305},{8172,6709},{1332,9542},{4036,1356},{161,9247},{5318,9801},{8672,9072},{5147,2675},{2892,8930},{1505,9763},{4711,5187},{3323,3291},{9107,2452},{4911,9644},{4522,7065},{198,6558},{1591,5197},{2815,4012},{2747,2347},{9340,2469},{5321,9878},{6835,6765},{2073,3042},{5374,2953},{8425,8056},{3900,103},{1655,342},{8030,3252},{7304,2173},{1098,3235},{629,3009},{3500,6909},{7081,7837},{5168,9979},{196,2268},{9177,7950},{2603,2401},{318,1384},{1189,9184},{6887,3920},{3823,2514},{244,2130},{5017,8517},{7558,205},{1880,1114},{5812,2883},{9970,7510},{7192,7820},{7508,5825},{7151,3},{5695,9018},{7581,3863},{8599,5344},{2935,5644},{483,3834},{2774,4072},{3808,1649},{6971,2006},{9374,8241},{4277,8934},{4145,7836},{7468,9883},{1281,2838},{8730,6780},{218,4602},{9741,5203},{2557,6531},{5607,5825},{3262,6932},{3086,6200},{7556,1873},{1436,3663},{3835,4340},{3263,1442},{6261,9817},{6794,2256},{2213,2705},{7395,6059},{3651,9811},{6723,1227},{8267,5367},{4681,4971},{493,1097},{4759,603},{9054,6252},{7012,8060},{9446,1236},{4728,3847},{5057,1771},{7779,3063},{7230,1517},{1334,2218},{9571,6075},{5192,4868},{630,4300},{9586,3323},{8469,8584},{1604,12},{1760,2667},{5774,7605},{5737,4808},{3031,4041},{8907,243},{5802,9919},{6112,9942},{3572,3171},{8490,5773},{2808,4916},{1211,5658},{7579,4628},{1100,4977},{4455,3467},{8458,1277},{108,8341},{5236,1290},{5771,5807},{1887,1432},{7689,2030},{8882,7199},{7314,3640},{3146,3189},{4756,1496},{3479,3129},{9775,5006},{4045,7996},{8956,9677},{612,4771},{8211,8540},{3705,4791},{7331,8262},{8715,1876},{1022,2618},{4734,1341},{9786,1819},{9515,886},{6097,2624},{5886,9353},{9058,8757},{7175,5394},{8158,3977},{5930,4963},{6923,5566},{5823,401},{9973,7501},{6274,8228},{1992,5631},{7652,1099},{5639,5732},{6216,4742},{5512,800},{9191,1322},{1830,4761},{9053,3457},{2926,6347},{6713,5079},{850,8644},{3025,1678},{9817,1768},{9964,955},{7853,2126},{966,215},{4731,8000},{3743,7630},{8359,1775},{3164,2851},{5253,5326},{6069,3962},{2049,8354},{8917,8525},{3480,6936},{750,1160},{685,6911},{946,6285},{2693,729},{7339,7489},{6667,4447},{8867,5213},{333,2762},{4269,3710},{9932,155},{9627,6997},{9600,675},{6485,9303},{3186,5100},{2904,2686},{7457,9902},{3124,6854},{3790,7834},{286,5105},{9807,6995},{1852,436},{4495,6048},{3835,9704},{3676,1612},{5197,1401},{5512,1606},{3075,9818}}, queries= {{5274,3953},{5479,7440},{9706,1669},{2405,4658},{2568,9420},{7981,4624},{1509,6774},{6323,9529},{520,3350},{4127,3891},{2730,4114},{8270,8966},{6202,4454},{2511,5425},{219,498},{5302,5652},{1601,7240},{1468,9749},{7912,5855},{4093,3627},{5021,8499},{8760,3606},{6402,2402},{51,7973},{622,2448},{4821,7806},{2715,9828},{6154,2649},{9383,3641},{3875,2197},{3907,7774},{2083,2626},{8151,6902},{6179,6},{8924,8089},{3598,8841},{8240,9409},{6886,5656},{8710,318},{5917,3109},{3203,4371},{5885,8693},{882,6774},{6065,2833},{9073,676},{3129,8550},{6514,5754},{5082,7285},{8827,877},{5468,323},{4726,8723},{2842,4026},{8434,5368},{2325,6743},{4144,3626},{1826,4042},{3926,6846},{9479,3657},{704,3897},{3602,9260},{5002,5511},{6498,6354},{7223,1015},{2124,411},{4301,2508},{2151,8013},{8647,6654},{8656,8400},{1346,3607},{5191,6033},{9648,7031},{4256,2514},{9000,561},{4436,2088},{8436,6779},{941,6812},{4401,5186},{8637,5515},{6642,1140},{2408,4150},{4686,307},{7445,1731},{6190,7081},{1393,8714},{7088,1839},{6892,8856},{5958,4244},{7241,3519},{2168,8380},{1858,7620},{5565,6766},{3395,5232},{4630,3637},{7290,1776},{7236,1729},{4014,8966},{301,9859},{1141,5557},{3163,1812},{5083,9128},{7228,2622},{4514,7196},{3843,1041},{1485,8481},{8534,8960},{3955,2045},{3518,2578},{2418,745},{4746,2673},{474,7330},{4236,2142},{4446,3961},{8986,2555},{7319,9268},{6030,6815},{4368,7642},{9415,4086},{2987,6235},{5254,879},{426,5398},{4322,4428},{7687,4097},{1188,2597},{7084,5173},{9004,373},{7820,7071},{730,1739},{4297,8625},{4357,6347},{6347,9246},{6728,5707},{9887,625},{1968,5030},{325,6535},{4479,3260},{4690,176},{908,4048},{3516,5058},{2545,3321},{9201,8694},{4140,3889},{8256,7401},{1742,5049},{1373,3757},{9711,2275},{9442,309},{7688,759},{9689,812},{8039,3007},{291,5935},{2095,378},{2020,2398},{4261,76},{9396,7871},{9764,5901},{6463,4571},{266,2374},{9238,8351},{9529,4279},{8460,7869}};

    
    auto res = sol.gridIllumination(N, lamps, queries);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    return 0;
}

