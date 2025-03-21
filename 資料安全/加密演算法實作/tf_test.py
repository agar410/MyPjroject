import tensorflow as tf
tf.compat.v1.disable_eager_execution()
class SquareTest(tf.test.TestCase):
    def testSquare(self):
        with self.test_session():
            x = tf.square([2, 3])
            self.assertAllEqual(x.eval(), [4, 9])

if __name__ == '__main__':
    print(tf.add(1, 2),'mytest') 
    tf.test.main()
    