class Solution {
    public List<String> letterCombinations(String digits) {
        List<List<String>> list = new ArrayList<List<String>>();

        if(digits.length() == 0)
            return new ArrayList<String>();

        List<String> _2 = new ArrayList<String>();
        _2.add("a");
        _2.add("b");
        _2.add("c");

        list.add(_2);

        List<String> _3 = new ArrayList<String>();
        _3.add("d");
        _3.add("e");
        _3.add("f");

        list.add(_3);

        List<String> _4 = new ArrayList<String>();
        _4.add("g");
        _4.add("h");
        _4.add("i");

        list.add(_4);

        List<String> _5 = new ArrayList<String>();
        _5.add("j");
        _5.add("k");
        _5.add("l");

        list.add(_5);

        List<String> _6 = new ArrayList<String>();
        _6.add("m");
        _6.add("n");
        _6.add("o");

        list.add(_6);

        List<String> _7 = new ArrayList<String>();
        _7.add("p");
        _7.add("q");
        _7.add("r");
        _7.add("s");

        list.add(_7);

        List<String> _8 = new ArrayList<String>();
        _8.add("t");
        _8.add("u");
        _8.add("v");

        list.add(_8);

        List<String> _9 = new ArrayList<String>();
        _9.add("w");
        _9.add("x");
        _9.add("y");
        _9.add("z");

        list.add(_9);

        System.out.println("\"" + digits + "\"");
        //System.out.println("digit 0:: " + digits.charAt(0));// + " --- " + (digits.charAt(0)));
        List<String> a = list.get(digits.charAt(0) - '2');
        for(int i = 1; i < digits.length(); i++)
        {
            List<String> b = list.get(digits.charAt(i) - '2');
            a = merge(a, b);
        }

        return a;
    }

    List<String> merge(List<String> a, List<String> b)
    {
        List<String> list = new ArrayList<String>();

        for(int i = 0; i < a.size(); i++)
            for(int j = 0; j < b.size(); j++)
                list.add(a.get(i) + b.get(j));

        return list;
    }
}