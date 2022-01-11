class Solution {
    public String simplifyPath(String path) {
		List<String> res = new ArrayList<>();
		String[] names = path.split("/");

		for (String str : names)
			if (str.length() != 0 && !str.equals("."))
				if (str.equals("..")) {
					if (res.size() > 0)
						res.remove(res.size() - 1);
				} else
					res.add(str);

		StringBuilder sb = new StringBuilder();

		for (String str : res)
			sb.append("/").append(str);

		return res.size() == 0 ? "/" : sb.toString();
	}
}

