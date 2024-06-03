sort(task.begin(),task.end());
  multiset<int>s;
  long long sum=0;
  int ans=0;

  for(int i=0;i<n;i++){
        sum+=1LL*task[i][1];
        s.insert(-task[i][1]);
        long long time = 2LL*task[i][0];
        while(!s.empty() && sum+time>1LL*t){
              sum+=1LL*(*s.begin());
              s.erase(s.begin());
        }
        ans=max(ans,(int)s.size());
  }

  return ans;