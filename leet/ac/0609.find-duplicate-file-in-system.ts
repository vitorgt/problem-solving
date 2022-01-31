function findDuplicate(paths: string[]): string[][] {
  let dirs: string[] = []
  let rep: {
    [x: string]: [string, number][]
  } = {}
  let ans: string[][] = []
  for (let i = 0; i < paths.length; i++) {
    const split = paths[i].split(" ")
    dirs.push(split[0])
    for (let j = 1; j < split.length; j++) {
      const [_full, file, content] = split[j].match(
        /(\w*\.txt)\(([\w\d]+)\)/i,
      )
      if (!rep[content]) rep[content] = []
      rep[content].push([file, i])
    }
  }
  for (const r in rep) {
    if (rep[r].length > 1) {
      let conten: string[] = []
      rep[r].forEach(([file, dir]) => {
        conten.push(`${dirs[dir]}/${file}`)
      })
      ans.push(conten)
    }
  }
  return ans
}
