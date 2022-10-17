const inputs = require('fs').readFileSync(0).toString().trim().split('\n');
const [n, m] = inputs[0].split(' ').map(Number);
inputs.shift();
const visited = inputs.map(line => line.split(''));

let queue = [];

const dx = [1, 0, -1, 0];
const dy = [0, 1, 0, -1];

const bfs = function (startNode) {
    queue.push(startNode);

    while (queue.length > 0) {
        const element = queue.shift();
        
        for (let i = 0; i < 4; i++) {
            const nx = element.x + dx[i];
            const ny = element.y + dy[i];
    
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && visited[nx][ny] == 1) {
                visited[nx][ny] = Number(visited[element.x][element.y]) + 1;
                queue.push({x: nx, y: ny});
            }
        }
    }
    const answer = visited[n - 1][m - 1];
    console.log(answer);
}

bfs({x:0, y:0});