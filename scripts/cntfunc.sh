do_file_split ()
{

LCNT=0
OLDLCNT=0
OLDFUNC=

 grep -n '#FUNC' lists.c | 
 while read LIN 
  do
   LCNT=$(echo $LIN | awk -F: '{print $1}' );
   FNAME=$(echo $LIN | awk '{print $3}' );

   echo "--------\> $FNAME"

#  echo $OLDLCNT $LCNT $FNAME
   let LINECNT="$(( $LCNT - $OLDLCNT ))"
   head -$LCNT lists.c | tail -$LINECNT

#   echo $LINECNT

   OLDLCNT=$LCNT
   OLDFUNC=$FNAME
  done


}
