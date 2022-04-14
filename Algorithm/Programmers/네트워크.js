let arr = [];
function dfs(now, computers, n) {
    for(let i=0;i<n;i++){
        let temp = arr[i];
        if(temp === false && computers[now][i]){
            arr[i] = true;
            dfs(i, computers, n)
        }
    }
}
function solution(n, computers) {
    var answer = 0;
    arr.length = n;
    arr.fill(false);
    for(let i=0;i<n;i++){
        if(arr[i] === false) {
            arr[i] = true;
            answer++;
            dfs(i, computers, n);
        }
    }
    return answer;
}
