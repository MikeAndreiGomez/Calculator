#include <iostream>

#include <algorithm>

#include <vector>

#include <string>

using namespace std;



class russianDoll{

    public:

        static bool enve(vector <int> a, vector <int> b) {

            if (a[0] == b[0]) return a[1] > b[1];

            return a[0] < b[0];

        } 

        int Envelope(vector<vector<int>>& v) {

            sort(v.begin(), v.end(), enve);

            if(v.size() == 0) return 0;

            vector <int> ret;

            for (int i = 0; i < v.size(); i++) {

                vector <int> temp = v[i];

                int x = temp[1];

                int width = 0;

                int height = ret.size() - 1;

                int curr = 0;

                while(width <= height) {

                    int mid = width + (height - width) / 2;

                    if(ret[mid]<temp[1]) {

                        curr = mid + 1;

                        width = mid + 1;

                    }

                    else {

                        height = mid - 1;

                    }

                }

                if (curr < 0) continue;

                if (curr >= (int) ret.size()) {

                    ret.push_back(temp[1]);;

                }

                else {

                    ret[curr] = temp[1];

                }

            }

            return ret.size();

        }

};



int main(){

    russianDoll ob;

    vector<vector<int>> v = {{5,4}, {6,4}, {6,7}, {2,3}};

    cout << (ob.Envelope(v));

}
