function ListNode(val, next) {
  this.val = (val===undefined ? 0 : val)
  this.next = (next===undefined ? null : next)
}

var mergeTwoLists = function(list1, list2) {
  const ans = [...list1, ...list2].sort((a, b) => a - b);
  //const ans = list1.concat(list2).sort();
  //왜 leetcode 런타임 환경에서는 concat을 인식을 못하지?
  // 연결리스트로 구현해야하는 것 같음
  console.log(ans)
  return ans;
};

//노드로 구현하면은 입력값을 어떻게 이용해야할지 잘 모르겠는???

mergeTwoLists([1, 2, 4], [1, 3, 4])