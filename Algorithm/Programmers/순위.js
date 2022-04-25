function dfsUp(num, res, visited) {
    let q = [];
    q.push(num);
    visited[num] = true;
    
    let cnt = 0;
    
    while(q.length > 0) {
        const qf = q[0];

        q.shift();
        for(let r of res){
            let from = r[1], togo = r[0];
            
            if(visited[togo] === true) {
                continue;
            }
            
            if(from === qf){
                cnt++;
                visited[togo] = true;
                q.push(togo);
            }
        }
    }

    return cnt;
}
function dfsDown(num, res, visited) {
    let q = [];
    q.push(num);
    visited[num] = true;
    
    let cnt = 0;
    
    while(q.length > 0) {
        const qf = q[0];

        q.shift();
        for(let r of res){
            let from = r[0], togo = r[1];
            
            if(visited[togo] === true) {
                continue;
            }
            
            if(from === qf){
                cnt++;
                visited[togo] = true;
                q.push(togo);
            }
        }
    }

    return cnt;
}
function solution(n, res) {
    var answer = 0;
    let visited = [];
    visited.length = n+1;
    for(let i=1;i<=n;i++){
        let cnt = 1;
        visited.fill(false);
        cnt += dfsDown(i, res, visited)
        cnt += dfsUp(i, res, visited)
        if(cnt === n) {
            answer++;
        }
    }
    return answer;
}
