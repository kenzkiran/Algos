/***
 * Ways to Score is a simple recursion based solution to identify
 * all possible ways to reach a 'final score' if the units of
 * scoring were 'units'
 */

var units = [2,5,7];
var finalScore = 17;

function generateSequence(val, seq)
{
    for(var i = units.length - 1; i >= 0; i--) {
        if (val >= units[i]) {
            var newVal = val - units[i];
            if( newVal === 0) {
                var goodSeq = seq.concat(units[i]);
                console.log('Sequence: ' +  JSON.stringify(goodSeq));
            } else {
                seq.push(units[i]);
                generateSequence(newVal, seq);
                seq.pop();
            }
        }
    }
}

var seq = [];
generateSequence(finalScore, seq);