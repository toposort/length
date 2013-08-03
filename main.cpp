#include <cstdio>
#include <cstring>
#include <string>
#include <map>

const int maxn = 10011;
char str[maxn], s[maxn];
std::map<std::string, double>mp;
std::map<std::string, std::string>mp1;

void init(){
    mp1["mile"] = "miles";
    mp1["yard"] = "yards";
    mp1["inch"] = "inches";
    mp1["foot"] = "feet";
    mp1["fath"] = "faths";
    mp1["furlong"] = "furlongs";
}

bool isdigit(char c){
    if(c>='0' && c<='9') return true;
    return false;
}

bool isletter(char c){
    if((c>='A' && c<='Z') || (c>='a' && c<='z')) return true;
    return false;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    init();
    puts("pony1993@126.com\n");
    while(1){
        double a, b;
        gets(str);
        if(strcmp(str, "")==0) break;
        sscanf(str, "%lf %s = %lf%*s", &a, s, &b);
        mp[s] = b/a;
        mp[mp1[s]] = b/a;
    }
    mp["m"] = 1.0;
    while(1){
        bool flag = false, op = false;
        while(1){
            int len = 0, sta;
            double res, tmp1;
            while(1){
                sta = scanf("%c", &str[len++]);
                if(str[len-1]==' '){
                    str[len-1] = 0;
                    break;
                }
                if(str[len-1]=='\n'){
                    str[len-1] = 0;
                    flag = true;
                    len = 0;
                    break;
                }
                if(sta==EOF) return 0;
            }
            if(strcmp(str,"")==0) continue;
            if(isdigit(str[0])) sscanf(str, "%lf", &tmp1);
            else if(isletter(str[0])){
                tmp1 *= mp[str];
                if(!op) res += tmp1;
                else res -= tmp1;
            }
            else if(str[0]=='-') op = true;
            else if(str[0]=='+') op = false;
            if(flag){
                flag = false;
                op = false;
                printf("%.2f m\n", res);
                res = tmp1 = 0;
                break;
            }
        }
    }
    return 0;
}
