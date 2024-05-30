public class RandomizedSet {

    public HashSet<int> HSet {get; set;}
    public Random Random {get; set;}

    public RandomizedSet() {
        HSet = new HashSet<int>();
        Random = new Random();
    }
    
    public bool Insert(int val) {
        return HSet.Add(val);
    }
    
    public bool Remove(int val) {
        return HSet.Remove(val);
    }
    
    public int GetRandom() {
        int randomIt = Random.Next(0, HSet.Count);
        foreach(var val in HSet){
            if(randomIt <= 0)
                return val;
            randomIt--;
        }
        return HSet.ToArray()[0];
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.Insert(val);
 * bool param_2 = obj.Remove(val);
 * int param_3 = obj.GetRandom();
 */