let path = [];
let ticketCnt = new Map();
let used = new Map();
function initDfs(dict, len) {

    return function dfs(now, cnt) {
        path.push(now);
        if(cnt === len) {
            return true;
        }
        if(dict.get(now) === undefined){
            return false;
        }
        let togo = dict.get(now).sort();
        
        for(let go of togo){
            let usedCnt = used.get(now + go), tickCnt = ticketCnt.get(now+go) 
            if(usedCnt < tickCnt ){
                used.set(now + go, usedCnt + 1);

                if (dfs(go, cnt+1) === false){
                    used.set(now + go, usedCnt);
                    path.pop(now);
                }
                else{
                    return true;
                }

            }
        }
        return false;
    }
}
function solution(tickets) {
    var answer = [];
    
    let dict = new Map();
    
    for(let ticket of tickets) {
        const start = ticket[0], end = ticket[1];
        const se = start + end;
        if(ticketCnt.get(se) === undefined) {
            ticketCnt.set(se, 0);
            used.set(se, 0);
        }
        ticketCnt.set(se, ticketCnt.get(se) + 1);
        if(dict.get(start) === undefined){
            dict.set(start, []);
        }
        let temp = dict.get(start);
        temp.push(end);
        dict.set(start, temp);
    }
    let foo = initDfs(dict, tickets.length);
    foo('ICN', 0)
    return path;
}
