function bfs(b, t, words) {
    let q = [];
    let l = [];
    let dict = new Map();
    
    q.push(b);
    l.push(0);
    dict.set(b, true);
    
    return function () {
        while(q.length > 0) {
            let qf = q[0];
            let lf = l[0];
            
            if(qf === t){
                return lf;
            }
            
            q.shift();
            l.shift();
            
            for(let word of words) {
                if( dict.get(word) === true){
                    continue;
                }
                let cnt = 0;
                for(let i=0,len=word.length;i<len;i++) {
                    if(word[i] !== qf[i] ){
                        cnt++;
                    }
                }
                if(cnt === 1){
                    dict.set(word, true);
                    q.push(word);
                    l.push(lf+1);
                }
            }
        }
        return 0;
    }
}
function solution(begin, target, words) {
    var answer = 0;
    answer = (bfs(begin, target, words))();
    return answer;
}
