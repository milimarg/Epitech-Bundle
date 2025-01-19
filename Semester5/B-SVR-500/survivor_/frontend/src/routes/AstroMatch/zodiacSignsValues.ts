import { ZodiacSign } from "../../utils/types";

type CompatibilityMatrix = {
  [sign in ZodiacSign]: Readonly<{ [otherSign in ZodiacSign]: number }>;
};

const zodiacSigns: ZodiacSign[] = [
  'Aries', 'Taurus', 'Gemini', 'Cancer', 'Leo', 'Virgo', 'Libra', 'Scorpio', 'Sagittarius', 'Capricorn', 'Aquarius', 'Pisces'
];

const compatibilityScores: ReadonlyArray<ReadonlyArray<number>> = [
  [85, 60, 70, 40, 90, 50, 75, 60, 95, 30, 70, 45], // ? Aries
  [60, 95, 55, 90, 50, 80, 65, 85, 40, 85, 45, 80], // ? Taurus
  [70, 55, 90, 50, 75, 65, 85, 60, 90, 40, 80, 50], // ? Gemini
  [40, 90, 50, 85, 45, 75, 70, 95, 55, 50, 60, 90], // ? Cancer
  [90, 50, 75, 45, 95, 60, 80, 65, 85, 35, 75, 55], // ? Leo
  [50, 80, 65, 75, 60, 90, 70, 80, 50, 85, 55, 65], // ? Virgo
  [75, 65, 85, 70, 80, 70, 90, 60, 75, 55, 80, 60], // ? Libra
  [60, 85, 60, 95, 65, 80, 60, 90, 55, 70, 65, 85], // ? Scorpio
  [95, 40, 90, 55, 85, 50, 75, 55, 90, 45, 70, 60], // ? Sagittarius
  [30, 85, 40, 50, 35, 85, 55, 70, 45, 90, 50, 55], // ? Capricorn
  [70, 45, 80, 60, 75, 55, 80, 65, 70, 50, 90, 60], // ? Aquarius
  [45, 80, 50, 90, 55, 65, 60, 85, 60, 55, 60, 85], // ? Pisces
];

export const compatibilityMatrix: CompatibilityMatrix = zodiacSigns.reduce<CompatibilityMatrix>((matrix, sign, i) => {
  matrix[sign] = zodiacSigns.reduce<{ [key in ZodiacSign]: number }>((row, otherSign, j) => {
    row[otherSign] = compatibilityScores[i][j];
    return row;
  }, {} as { [key in ZodiacSign]: number });
  return matrix;
}, {} as CompatibilityMatrix);
