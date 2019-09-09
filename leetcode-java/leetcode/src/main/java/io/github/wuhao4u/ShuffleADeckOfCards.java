package io.github.wuhao4u;

import java.util.Arrays;
import java.util.Random;

public class ShuffleADeckOfCards {

    public static void shuffle(int[] cards) {
        Random rand = new Random();

        for (int i = 0; i < cards.length; ++i) {
            int pos = i + rand.nextInt(52 - i);

            int temp = cards[i];
            cards[i] = cards[pos];
            cards[pos] = temp;
        }
    }

    public static void main(String[] args) {
        int a[] = new int[52];

        for (int i = 0; i < a.length; ++i) {
            a[i] = i+1;
            System.out.println(a[i]);
        }

        shuffle(a);

        System.out.println("----------------------------------------------------------");

        for (int i = 0; i < a.length; ++i) {
            System.out.println(a[i]);
        }
    }
}
