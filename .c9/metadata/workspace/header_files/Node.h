{"filter":false,"title":"Node.h","tooltip":"/header_files/Node.h","undoManager":{"mark":100,"position":100,"stack":[[{"group":"doc","deltas":[{"start":{"row":43,"column":0},"end":{"row":56,"column":0},"action":"remove","lines":["template <typename T>","bool Node<T>::shittyOperatorComparison(Node<T>* right)","{","    for(int i = 0; i < mSize; i++)","    {","        if(mData[i] != right->mData[i])","        {","            return false;","        }","    }","    return true;","}","#endif",""]}]}],[{"group":"doc","deltas":[{"start":{"row":43,"column":0},"end":{"row":56,"column":0},"action":"insert","lines":["template <typename T>","bool Node<T>::shittyOperatorComparison(Node<T>* right)","{","    for(int i = 0; i < mSize; i++)","    {","        if(mData[i] != right->mData[i])","        {","            return false;","        }","    }","    return true;","}","#endif",""]}]}],[{"group":"doc","deltas":[{"start":{"row":42,"column":2},"end":{"row":54,"column":1},"action":"remove","lines":["","template <typename T>","bool Node<T>::shittyOperatorComparison(Node<T>* right)","{","    for(int i = 0; i < mSize; i++)","    {","        if(mData[i] != right->mData[i])","        {","            return false;","        }","    }","    return true;","}"]}]}],[{"group":"doc","deltas":[{"start":{"row":42,"column":2},"end":{"row":54,"column":1},"action":"insert","lines":["","template <typename T>","bool Node<T>::shittyOperatorComparison(Node<T>* right)","{","    for(int i = 0; i < mSize; i++)","    {","        if(mData[i] != right->mData[i])","        {","            return false;","        }","    }","    return true;","}"]}]}],[{"group":"doc","deltas":[{"start":{"row":36,"column":1},"end":{"row":37,"column":0},"action":"insert","lines":["",""]}]}],[{"group":"doc","deltas":[{"start":{"row":37,"column":0},"end":{"row":38,"column":0},"action":"insert","lines":["",""]}]}],[{"group":"doc","deltas":[{"start":{"row":37,"column":0},"end":{"row":37,"column":4},"action":"insert","lines":["Node"]}]}],[{"group":"doc","deltas":[{"start":{"row":37,"column":4},"end":{"row":37,"column":7},"action":"insert","lines":["<T>"]}]}],[{"group":"doc","deltas":[{"start":{"row":37,"column":7},"end":{"row":37,"column":9},"action":"insert","lines":["::"]}]}],[{"group":"doc","deltas":[{"start":{"row":37,"column":9},"end":{"row":37,"column":12},"action":"insert","lines":["Nod"]}]}],[{"group":"doc","deltas":[{"start":{"row":37,"column":12},"end":{"row":37,"column":15},"action":"insert","lines":["e()"]}]}],[{"group":"doc","deltas":[{"start":{"row":37,"column":14},"end":{"row":37,"column":16},"action":"insert","lines":["T "]}]}],[{"group":"doc","deltas":[{"start":{"row":37,"column":16},"end":{"row":37,"column":20},"action":"insert","lines":["data"]}]}],[{"group":"doc","deltas":[{"start":{"row":37,"column":20},"end":{"row":37,"column":22},"action":"insert","lines":[", "]}]}],[{"group":"doc","deltas":[{"start":{"row":37,"column":22},"end":{"row":37,"column":25},"action":"insert","lines":["int"]}]}],[{"group":"doc","deltas":[{"start":{"row":37,"column":25},"end":{"row":37,"column":26},"action":"insert","lines":[" "]}]}],[{"group":"doc","deltas":[{"start":{"row":37,"column":26},"end":{"row":37,"column":30},"action":"insert","lines":["valu"]}]}],[{"group":"doc","deltas":[{"start":{"row":37,"column":30},"end":{"row":37,"column":31},"action":"insert","lines":["e"]}]}],[{"group":"doc","deltas":[{"start":{"row":37,"column":32},"end":{"row":38,"column":2},"action":"insert","lines":["","{}"]}]}],[{"group":"doc","deltas":[{"start":{"row":16,"column":16},"end":{"row":17,"column":25},"action":"insert","lines":["","   Node<T>::Node(T data);"]},{"start":{"row":39,"column":1},"end":{"row":41,"column":0},"action":"insert","lines":["","    ",""]}]}],[{"group":"doc","deltas":[{"start":{"row":40,"column":0},"end":{"row":40,"column":4},"action":"remove","lines":["    "]}]}],[{"group":"doc","deltas":[{"start":{"row":34,"column":1},"end":{"row":34,"column":5},"action":"remove","lines":["int "]},{"start":{"row":40,"column":0},"end":{"row":40,"column":12},"action":"insert","lines":["    mSize = "]}]}],[{"group":"doc","deltas":[{"start":{"row":40,"column":12},"end":{"row":41,"column":4},"action":"insert","lines":["data;","    "]}]}],[{"group":"doc","deltas":[{"start":{"row":40,"column":17},"end":{"row":41,"column":4},"action":"insert","lines":["","    "]},{"start":{"row":42,"column":4},"end":{"row":42,"column":17},"action":"insert","lines":["mNext = NULL;"]}]}],[{"group":"doc","deltas":[{"start":{"row":41,"column":4},"end":{"row":41,"column":17},"action":"insert","lines":["mData = new T"]}]}],[{"group":"doc","deltas":[{"start":{"row":41,"column":17},"end":{"row":41,"column":24},"action":"insert","lines":["[mSize]"]}]}],[{"group":"doc","deltas":[{"start":{"row":41,"column":24},"end":{"row":42,"column":9},"action":"insert","lines":[";","    mData"]}]}],[{"group":"doc","deltas":[{"start":{"row":41,"column":18},"end":{"row":41,"column":23},"action":"remove","lines":["mSize"]},{"start":{"row":41,"column":18},"end":{"row":41,"column":19},"action":"insert","lines":["1"]}]}],[{"group":"doc","deltas":[{"start":{"row":42,"column":9},"end":{"row":42,"column":21},"action":"insert","lines":["[0] = value;"]}]}],[{"group":"doc","deltas":[{"start":{"row":17,"column":3},"end":{"row":17,"column":12},"action":"remove","lines":["Node<T>::"]},{"start":{"row":38,"column":22},"end":{"row":38,"column":25},"action":"remove","lines":["int"]},{"start":{"row":38,"column":22},"end":{"row":38,"column":23},"action":"insert","lines":["T"]}]}],[{"group":"doc","deltas":[{"start":{"row":17,"column":14},"end":{"row":17,"column":22},"action":"insert","lines":[", T data"]}]}],[{"group":"doc","deltas":[{"start":{"row":44,"column":1},"end":{"row":48,"column":1},"action":"insert","lines":["","Node<T>::Node(T data, T value)","{","    ","}"]}]}],[{"group":"doc","deltas":[{"start":{"row":45,"column":23},"end":{"row":45,"column":24},"action":"insert","lines":["*"]}]}],[{"group":"doc","deltas":[{"start":{"row":11,"column":18},"end":{"row":11,"column":43},"action":"remove","lines":["0 size is one array uptop"]},{"start":{"row":11,"column":18},"end":{"row":11,"column":19},"action":"insert","lines":["n"]}]}],[{"group":"doc","deltas":[{"start":{"row":11,"column":19},"end":{"row":11,"column":20},"action":"insert","lines":["o"]}]}],[{"group":"doc","deltas":[{"start":{"row":11,"column":20},"end":{"row":11,"column":21},"action":"insert","lines":[" "]}]}],[{"group":"doc","deltas":[{"start":{"row":11,"column":21},"end":{"row":11,"column":23},"action":"insert","lines":["no"]}]}],[{"group":"doc","deltas":[{"start":{"row":11,"column":23},"end":{"row":11,"column":30},"action":"insert","lines":["ooooooa"]}]}],[{"group":"doc","deltas":[{"start":{"row":11,"column":30},"end":{"row":11,"column":49},"action":"insert","lines":["aaaaaaaaaaaaaaaaaaa"]}]}],[{"group":"doc","deltas":[{"start":{"row":11,"column":49},"end":{"row":11,"column":52},"action":"insert","lines":["aaa"]}]}],[{"group":"doc","deltas":[{"start":{"row":11,"column":29},"end":{"row":11,"column":30},"action":"insert","lines":[" "]}]}],[{"group":"doc","deltas":[{"start":{"row":47,"column":4},"end":{"row":47,"column":13},"action":"insert","lines":["for(int )"]}]}],[{"group":"doc","deltas":[{"start":{"row":11,"column":49},"end":{"row":11,"column":50},"action":"remove","lines":["a"]}]}],[{"group":"doc","deltas":[{"start":{"row":11,"column":49},"end":{"row":11,"column":50},"action":"remove","lines":["a"]}]}],[{"group":"doc","deltas":[{"start":{"row":11,"column":49},"end":{"row":11,"column":50},"action":"remove","lines":["a"]}]}],[{"group":"doc","deltas":[{"start":{"row":11,"column":49},"end":{"row":11,"column":50},"action":"remove","lines":["a"]}]}],[{"group":"doc","deltas":[{"start":{"row":16,"column":10},"end":{"row":16,"column":14},"action":"remove","lines":["data"]},{"start":{"row":16,"column":10},"end":{"row":16,"column":12},"action":"insert","lines":["si"]}]}],[{"group":"doc","deltas":[{"start":{"row":16,"column":12},"end":{"row":16,"column":14},"action":"insert","lines":["ze"]}]}],[{"group":"doc","deltas":[{"start":{"row":17,"column":10},"end":{"row":17,"column":14},"action":"remove","lines":["data"]},{"start":{"row":17,"column":10},"end":{"row":17,"column":11},"action":"insert","lines":["s"]}]}],[{"group":"doc","deltas":[{"start":{"row":17,"column":11},"end":{"row":17,"column":14},"action":"insert","lines":["ize"]}]}],[{"group":"doc","deltas":[{"start":{"row":11,"column":21},"end":{"row":11,"column":30},"action":"remove","lines":["nooooooo "]}]}],[{"group":"doc","deltas":[{"start":{"row":32,"column":16},"end":{"row":32,"column":20},"action":"remove","lines":["data"]},{"start":{"row":32,"column":16},"end":{"row":32,"column":20},"action":"insert","lines":["size"]},{"start":{"row":34,"column":9},"end":{"row":34,"column":13},"action":"remove","lines":["data"]},{"start":{"row":34,"column":9},"end":{"row":34,"column":13},"action":"insert","lines":["size"]},{"start":{"row":38,"column":16},"end":{"row":38,"column":20},"action":"remove","lines":["data"]},{"start":{"row":38,"column":16},"end":{"row":38,"column":20},"action":"insert","lines":["size"]}]}],[{"group":"doc","deltas":[{"start":{"row":40,"column":12},"end":{"row":40,"column":16},"action":"remove","lines":["data"]},{"start":{"row":40,"column":12},"end":{"row":40,"column":16},"action":"insert","lines":["size"]},{"start":{"row":45,"column":16},"end":{"row":45,"column":20},"action":"remove","lines":["data"]},{"start":{"row":45,"column":16},"end":{"row":45,"column":20},"action":"insert","lines":["size"]}]}],[{"group":"doc","deltas":[{"start":{"row":47,"column":11},"end":{"row":47,"column":14},"action":"insert","lines":[" i "]}]}],[{"group":"doc","deltas":[{"start":{"row":47,"column":14},"end":{"row":47,"column":16},"action":"insert","lines":["= "]}]}],[{"group":"doc","deltas":[{"start":{"row":47,"column":16},"end":{"row":47,"column":18},"action":"insert","lines":["0 "]}]}],[{"group":"doc","deltas":[{"start":{"row":47,"column":17},"end":{"row":47,"column":18},"action":"remove","lines":[" "]},{"start":{"row":47,"column":17},"end":{"row":47,"column":19},"action":"insert","lines":["; "]}]}],[{"group":"doc","deltas":[{"start":{"row":47,"column":19},"end":{"row":47,"column":23},"action":"insert","lines":["i < "]}]}],[{"group":"doc","deltas":[{"start":{"row":47,"column":22},"end":{"row":47,"column":23},"action":"remove","lines":[" "]},{"start":{"row":47,"column":22},"end":{"row":47,"column":23},"action":"insert","lines":["="]}]}],[{"group":"doc","deltas":[{"start":{"row":47,"column":23},"end":{"row":47,"column":27},"action":"insert","lines":["size"]}]}],[{"group":"doc","deltas":[{"start":{"row":47,"column":27},"end":{"row":47,"column":30},"action":"insert","lines":["; i"]}]}],[{"group":"doc","deltas":[{"start":{"row":47,"column":30},"end":{"row":47,"column":31},"action":"insert","lines":["+"]}]}],[{"group":"doc","deltas":[{"start":{"row":47,"column":31},"end":{"row":47,"column":32},"action":"insert","lines":["+"]}]}],[{"group":"doc","deltas":[{"start":{"row":47,"column":32},"end":{"row":47,"column":33},"action":"remove","lines":[" "]}]}],[{"group":"doc","deltas":[{"start":{"row":47,"column":33},"end":{"row":48,"column":5},"action":"insert","lines":["","    {"]}]}],[{"group":"doc","deltas":[{"start":{"row":48,"column":5},"end":{"row":50,"column":5},"action":"insert","lines":["","        ","    }"]}]}],[{"group":"doc","deltas":[{"start":{"row":41,"column":16},"end":{"row":41,"column":17},"action":"remove","lines":["T"]},{"start":{"row":41,"column":16},"end":{"row":41,"column":17},"action":"insert","lines":["T"]}]}],[{"group":"doc","deltas":[{"start":{"row":41,"column":18},"end":{"row":41,"column":19},"action":"remove","lines":["1"]},{"start":{"row":41,"column":18},"end":{"row":41,"column":22},"action":"insert","lines":["size"]}]}],[{"group":"doc","deltas":[{"start":{"row":37,"column":1},"end":{"row":38,"column":21},"action":"insert","lines":["","template <typename T>"]},{"start":{"row":45,"column":1},"end":{"row":46,"column":21},"action":"insert","lines":["","template <typename T>"]},{"start":{"row":49,"column":23},"end":{"row":49,"column":24},"action":"insert","lines":[" "]}]}],[{"group":"doc","deltas":[{"start":{"row":45,"column":1},"end":{"row":46,"column":2},"action":"insert","lines":["","/*"]},{"start":{"row":55,"column":0},"end":{"row":55,"column":2},"action":"insert","lines":["*/"]}]}],[{"group":"doc","deltas":[{"start":{"row":32,"column":14},"end":{"row":32,"column":15},"action":"remove","lines":["T"]},{"start":{"row":32,"column":14},"end":{"row":32,"column":15},"action":"insert","lines":["i"]}]}],[{"group":"doc","deltas":[{"start":{"row":32,"column":15},"end":{"row":32,"column":16},"action":"insert","lines":["n"]}]}],[{"group":"doc","deltas":[{"start":{"row":32,"column":16},"end":{"row":32,"column":17},"action":"insert","lines":["t"]}]}],[{"group":"doc","deltas":[{"start":{"row":39,"column":14},"end":{"row":39,"column":15},"action":"remove","lines":["T"]},{"start":{"row":39,"column":14},"end":{"row":39,"column":15},"action":"insert","lines":["i"]}]}],[{"group":"doc","deltas":[{"start":{"row":39,"column":15},"end":{"row":39,"column":16},"action":"insert","lines":["n"]}]}],[{"group":"doc","deltas":[{"start":{"row":39,"column":16},"end":{"row":39,"column":17},"action":"insert","lines":["t"]}]}],[{"group":"doc","deltas":[{"start":{"row":16,"column":8},"end":{"row":16,"column":9},"action":"remove","lines":["T"]},{"start":{"row":16,"column":8},"end":{"row":16,"column":9},"action":"insert","lines":["i"]}]}],[{"group":"doc","deltas":[{"start":{"row":16,"column":9},"end":{"row":16,"column":10},"action":"insert","lines":["n"]}]}],[{"group":"doc","deltas":[{"start":{"row":16,"column":10},"end":{"row":16,"column":11},"action":"insert","lines":["t"]}]}],[{"group":"doc","deltas":[{"start":{"row":17,"column":8},"end":{"row":17,"column":9},"action":"remove","lines":["T"]}]}],[{"group":"doc","deltas":[{"start":{"row":17,"column":8},"end":{"row":17,"column":9},"action":"insert","lines":["i"]}]}],[{"group":"doc","deltas":[{"start":{"row":17,"column":9},"end":{"row":17,"column":10},"action":"insert","lines":["n"]}]}],[{"group":"doc","deltas":[{"start":{"row":17,"column":10},"end":{"row":17,"column":11},"action":"insert","lines":["t"]}]}],[{"group":"doc","deltas":[{"start":{"row":35,"column":9},"end":{"row":35,"column":13},"action":"remove","lines":["NULL"]},{"start":{"row":35,"column":9},"end":{"row":35,"column":10},"action":"insert","lines":["n"]}]}],[{"group":"doc","deltas":[{"start":{"row":35,"column":10},"end":{"row":35,"column":11},"action":"insert","lines":["e"]}]}],[{"group":"doc","deltas":[{"start":{"row":35,"column":11},"end":{"row":35,"column":12},"action":"insert","lines":["w"]}]}],[{"group":"doc","deltas":[{"start":{"row":35,"column":12},"end":{"row":35,"column":13},"action":"insert","lines":[" "]}]}],[{"group":"doc","deltas":[{"start":{"row":35,"column":13},"end":{"row":35,"column":14},"action":"insert","lines":["T"]}]}],[{"group":"doc","deltas":[{"start":{"row":35,"column":14},"end":{"row":35,"column":16},"action":"insert","lines":["[]"]}]}],[{"group":"doc","deltas":[{"start":{"row":35,"column":15},"end":{"row":35,"column":16},"action":"insert","lines":["s"]}]}],[{"group":"doc","deltas":[{"start":{"row":35,"column":16},"end":{"row":35,"column":17},"action":"insert","lines":["i"]}]}],[{"group":"doc","deltas":[{"start":{"row":35,"column":17},"end":{"row":35,"column":18},"action":"insert","lines":["z"]}]}],[{"group":"doc","deltas":[{"start":{"row":35,"column":18},"end":{"row":35,"column":19},"action":"insert","lines":["e"]}]}],[{"group":"doc","deltas":[{"start":{"row":35,"column":19},"end":{"row":35,"column":20},"action":"insert","lines":["+"]}]}],[{"group":"doc","deltas":[{"start":{"row":35,"column":20},"end":{"row":35,"column":21},"action":"insert","lines":["1"]}]}],[{"group":"doc","deltas":[{"start":{"row":42,"column":22},"end":{"row":42,"column":23},"action":"insert","lines":[" "]}]}],[{"group":"doc","deltas":[{"start":{"row":42,"column":23},"end":{"row":42,"column":24},"action":"insert","lines":["="]}]}],[{"group":"doc","deltas":[{"start":{"row":42,"column":23},"end":{"row":42,"column":24},"action":"remove","lines":["="]}]}],[{"group":"doc","deltas":[{"start":{"row":42,"column":23},"end":{"row":42,"column":24},"action":"insert","lines":["+"]}]}],[{"group":"doc","deltas":[{"start":{"row":42,"column":24},"end":{"row":42,"column":25},"action":"insert","lines":["1"]}]}],[{"group":"doc","deltas":[{"start":{"row":42,"column":24},"end":{"row":42,"column":25},"action":"insert","lines":[" "]}]}]]},"ace":{"folds":[],"scrolltop":180,"scrollleft":0,"selection":{"start":{"row":42,"column":25},"end":{"row":42,"column":25},"isBackwards":true},"options":{"guessTabSize":true,"useWrapMode":false,"wrapToView":true},"firstLineState":{"row":206,"mode":"ace/mode/c_cpp"}},"timestamp":1417617920229,"hash":"29116d858c9c901c05a544508362dd512dd7260d"}