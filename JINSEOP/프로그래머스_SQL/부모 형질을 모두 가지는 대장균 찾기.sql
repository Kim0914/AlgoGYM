SELECT ed.ID, ed.GENOTYPE, ed2.GENOTYPE AS PARENT_GENOTYPE
FROM ECOLI_DATA ed LEFT OUTER JOIN ECOLI_DATA ed2 ON ed.PARENT_ID = ed2.ID
WHERE ~ed.GENOTYPE & ed2.GENOTYPE = 0
ORDER BY ed.ID

// LEFT OUTER JOIN을 통해서 자기참조 시킨다.
// 댓글, 대댓글을 만드는 원리와 동일함.
