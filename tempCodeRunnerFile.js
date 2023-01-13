ay(size);

for (var a = 0; a < size; a++) {

    rl.question("Element at position ${a}: ", function(answer) {
        myinputarr[a] = +answer;
        rl.close();
    });

}

//user eneter array
console.log(myinputarr);