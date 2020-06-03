

public class CommonTest {

	@Test
	public void test() {
		boolean reachable = NetAddressIsReachable.checkAddressReachable("127.0.0.1", 11211, 1000);
		System.out.println(reachable);
	}

	public static void main(String[] args) {
		List<Integer> arrayLi = new ArrayList<>();
		for (int i = 0; i < 20; i++) {
			arrayLi.add(i + 1);
		}
		// System.out.println(arrayLi);
		int o = 0;
		AtomicInteger miuber = new AtomicInteger(1);
		arrayLi.stream().forEach(inte -> {
			// System.out.println(inte);
		});
		// int[] a={8,11,19,19,19,19,23,27,33,45,55,67,98};
		// int[] a = { 1, 1, 1, 1, 2, 1, 3, 3, 3 };
		// int value = bsearchFirst(a, 9, 2);
		// System.out.println("va:" + value);
		// System.out.println("vas:" + bsearchend(a, 9, 2));
		// System.out.println("vas find:" + findindexLoweCoordinate(a, 9));

		// List<Integer> lsit= { 1, 1, 1, 2, 2, 2, 3, 3, 3};
		// List<Person> sortedList =
		// list.stream().sorted((o1,o2)->o1.getAge()-o2.getAge()).collect(Collectors.toList());
	
		int[] a = { 1, 1, 1,1, 2, 2, 2, 3, 3, 3, 1, 2 };
		 
		// int[] a = { 1, 1, 1,1, 2, 2, 1};
		//int[] a = { 2, 1, 1, 1, 2, 2, 1 };
		 //int[] a = {1,1,3 };
		// List 转int[]
		int[] bx = arrayLi.stream().mapToInt(Integer::valueOf).toArray();
		System.out.println("List 转int[]:" + bx.length);
		// int[] 转Integer[]
		Integer[] integers1 = Arrays.stream(a).boxed().toArray(Integer[]::new);
		// Integer[] 转 List<Integer>
		List<Integer> list2 = Arrays.asList(integers1);
		
		List<Integer> listHou = removeAfterLessThan(list2);
		int[] nx= {1, 1, 1, 1, 2, 2, 2, 3, 3, 3};
		//System.out.println("1等级首sss次出现的下标:：{}" + bsearchFirst(nx,1,nx.length));
		Map<String, Long> params = getElementCcurrencesSum(listHou);
		System.out.println("在数组总出现次数params::{}:" +params);
		IntStream.rangeClosed(0, 10).parallel().forEach(i -> {
			//
		});
		
		for(int i=1;i<4;i++) {
			System.out.println(i+"等级出现的次数:" + getixBolPannul(params,getIndeCfxvx(i))+","+
					i+"等级首次出现的下标:"+getfirstIndexClox(params,getIndeCfxvx(i),listHou)+","+
					i+"等级最后出现的下标:"+getLastIndexClox(params,getIndeCfxvx(i),listHou));
		}
		//循环处理2等级的数据
		int startV=getfirstIndexClox(params,getIndeCfxvx(2),listHou);
		int endsV=getLastIndexClox(params,getIndeCfxvx(2),listHou);
		for(;startV<=endsV;startV++) {
			//System.out.println("在数组总出现次数params startV::{}:index:" +startV+","+listHou.get(startV));
		}
		System.out.println("-----------------------");
		for(int i=1;i<4;i++) {
			//System.out.println(i+"等级首次出现的下标:" +start(list2,i));
		}
		  for(int i = 1;i<=26;i++) {
			  char s=(char)(96+i);
		    	 System.out.println(String.valueOf(s).toUpperCase());
		    }
		
		//System.out.println("1等级出现的次数:：{}" + getixBolPannul(params,1));
		//System.out.println("1等级首次出现的下标:：{}" + getfirstIndexClox(params,1,listHou));
		//System.out.println("1等级最后出现的下标:：{}" + getLastIndexClox(params,1,listHou));
	}
	
	public static int start(List<Integer> listAll,int gradex) {
		int startV=getfirstIndexClox(
				getElementCcurrencesSum(removeAfterLessThan(listAll)),
				getIndeCfxvx(gradex), 
				removeAfterLessThan(listAll));
		return startV;
	}
	

	public static int getixBolPannul(Map<String, Long> params,String indeVc) {
		int ret = 0;
		if (params.get(indeVc) != null) {
			return params.get(indeVc).intValue();
		}
		return ret;
	}

	public static int getIndexvx(String indexGrade) {
		if("A".endsWith(indexGrade)) {
			return 1;
		}
		if("B".endsWith(indexGrade)) {
			return 2;
		}
		if("C".endsWith(indexGrade)) {
			return 3;
		} 
		return -1;
	}
	public static String getIndeCfxvx(int indexGrade) {
		if(indexGrade==1) {
			return "A";
		}
		if(indexGrade==2) {
			return "B";
		}
		if(indexGrade==3) {
			return "C";
		}
		return "";
	}
	public static int getfirstIndexClox(Map<String, Long> params,String indexGrade, List<Integer> listHou) {
		int ret=getixBolPannul(params,indexGrade);
		if(ret>=1) {
			int[] bxV = listHou.stream().mapToInt(Integer::valueOf).toArray();
			int va=bsearchFirst(bxV,getIndexvx(indexGrade),bxV.length);
			if(va<0) {
				return 0;
			}
			return va;	
		}
		return 0;

	}
	public static int getLastIndexClox(Map<String, Long> params,String indexGrade, List<Integer> listHou) {
		int ret=getixBolPannul(params,indexGrade);
		if(ret>=1) {
			int[] bxV = listHou.stream().mapToInt(Integer::valueOf).toArray();
			int va= bsearchend(bxV,getIndexvx(indexGrade),bxV.length);
			if(va<0) {
				return 0;
			}
			return va;
		}
		return 0;

	}
	// 1把集合转变成int[] 去除其中后面一个小于前面一个 后面所有的数据
	public static List<Integer> removeAfterLessThan(List<Integer> valueList) {
		System.out.println("去除之前的数据data:{}" + valueList);
		if (valueList.size() <= 1) {
			return valueList;
		}
		int[] firstV = valueList.stream().mapToInt(Integer::valueOf).toArray();
		int indexV = findindexLoweCoordinate(firstV, firstV.length);
		if (indexV != -1) {
			valueList.stream().filter(a -> indexV > valueList.size()).collect(Collectors.toList());
			IntStream.rangeClosed(1, indexV).parallel().forEach(i -> {
			});// System.out.println("item-->I:{}" + i);});
				// 获取前5个权限对象组成的集合
			List<Integer> firstFiveList = valueList.stream().limit(indexV + 1).collect(Collectors.toList());
			System.out.println("去除之后的数据data:{}" + firstFiveList);
			return firstFiveList;
		}
		return valueList;
	}

	// 2:查询 后面小于前面的 index
	public static int findindexLoweCoordinate(int[] a, int n) {
		int low = 0;
		int high = n - 1;
		if (n <= 1) {
			return 0;
		}
		while (low < high) {
			if (a[low] > a[low + 1]) {
				return low;
			}
			low = low + 1;
		}
		return -1;
	}

	public int bsearch(int[] a, int n, int value) {
		int low = 0;
		int high = n - 1;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (a[mid] == value) {
				return mid;
			} else if (a[mid] < value) {
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}
		return -1;
	}

	// 查询第一个出现的位置：
	public static int bsearchFirst(int[] a, int value, int n) {
		int low = 0;
		int high = n - 1;
		while (low <= high) {
			int mid = low + ((high - low) >> 1);
			// System.out.println("mid"+mid);
			if (a[mid] > value) {
				high = mid - 1;
			} else if (a[mid] < value) {
				low = mid + 1;
			} else {
				if ((mid == 0) || (a[mid - 1] != value))
					return mid;
				else
					high = mid - 1;
			}
		}
		return -1;
	}

	public static int bsearchend(int[] a,int value, int n) {
		int low = 0;
		int high = n - 1;
		while (low <= high) {
			int mid = low + ((high - low) >> 1);
			if (a[mid] > value) {
				high = mid - 1;
			} else if (a[mid] < value) {
				low = mid + 1;
			} else {
				if ((mid == n - 1) || (a[mid + 1] != value))
					return mid;
				else
					low = mid + 1;
			}
		}
		return -1;
	}

	public static Map<String, Long> getElementCcurrencesSum(List<Integer> list) {
		Map<Integer, Long> map = list.stream().collect(Collectors.groupingBy(p -> p, Collectors.counting()));
		Map<String, Long> params = new HashMap<>();
		// map.forEach((k, v) -> System.out.println(k + ":" + v));
		params.put("A", map.get(1));
		params.put("B", map.get(2));
		params.put("C", map.get(3));
		for (Integer key : map.keySet()) {
			//System.out.println("map.get(" + key + ") = " + map.get(key));
		}
		return params;
	}

}
