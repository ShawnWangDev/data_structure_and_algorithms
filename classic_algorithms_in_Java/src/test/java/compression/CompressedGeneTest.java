package compression;

import org.junit.jupiter.api.Test;
import study.compression.CompressedGene;

public class CompressedGeneTest {
    @Test
    public void test() {
        String geneStr = "ACGT";
        System.out.println("gene string: " + geneStr);
        CompressedGene compressedGene = new CompressedGene(geneStr);
        compressedGene.printIntroduction();
        System.out.println("bitSet length: " + compressedGene.getBitSet().length());
        // ACGT's binary form is 00011011, its index of 3, 4, 6, 7 are "1",
        // so print getBitSet() is {3, 4, 6, 7}
        System.out.println("print bitSet -> " + compressedGene.getBitSet());
        System.out.println("decompress: " + compressedGene.decompress());
    }
}
